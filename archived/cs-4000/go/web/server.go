package main

import (
    "github.com/go-martini/martini"
    "github.com/martini-contrib/render"
    "net/http"
    "io/ioutil"
    "encoding/json"
    "fmt"
    "net/url"
)

type Client struct {
    ID          string
	FirstName	string `json:"first_name"`
	LastName	string `json:"last_name"`
	Email		string
	Company		string
	Project		string
	Phone		string
}

func panicIf(error error) {
    if error != nil {
        panic(error)
    }
}

const ApiRoot = "http://localhost:8888/v1"

func makeGetRequest(url string) []byte {
    response, error := http.Get(ApiRoot + url)
    panicIf(error)
    body, error := ioutil.ReadAll(response.Body)
    panicIf(error)
    return body
}

func makePostFormRequest(url string, data url.Values) []byte {
    response, error := http.PostForm(ApiRoot + url, data)
    panicIf(error)
    body, error := ioutil.ReadAll(response.Body)
    panicIf(error)
    return body
}

//func makeDeleteRequest(url string) []byte {
//    response, error := http.Delete(ApiRoot + url)
//    panicIf(error)
//    body, error := ioutil.ReadAll(response.Body)
//    panicIf(error)
//    return body
//}


func getClients() []Client {
    clients := []Client{}
    data := makeGetRequest("/clients.json")
    error := json.Unmarshal(data, &clients)
    panicIf(error)
    return clients
}

func getClient(id string) Client {
    client := Client{}
    data := makeGetRequest(fmt.Sprintf("/clients/%s.json", id))
    error := json.Unmarshal(data, &client)
    panicIf(error)
    return  client
}

func createClient(client Client) Client {
    formData := url.Values{
        "first_name": {client.FirstName},
        "last_name": {client.LastName},
        "email": {client.Email},
        "company": {client.Company},
        "project": {client.Project},
        "phone": {client.Phone},
    }
    data := makePostFormRequest("/clients.json", formData)
    client = Client{}
    error := json.Unmarshal(data, &client)
    panicIf(error)
    return  client
}

func main() {
	m := martini.Classic()
	m.Use(render.Renderer(render.Options{
		Layout: "layout",
	}))
	m.Get("/", func(r render.Render) {
		r.HTML(200, "index", "Kaden")
	})

	// clients index
	m.Get("/clients", func(r render.Render) {
		clients := getClients()
		r.HTML(200, "clients/index", clients)
	})

    // client show
	m.Get("/clients/(?P<id>[0-9]+)", func(params martini.Params ,r render.Render) {
        client := getClient(params["id"])
        r.HTML(200, "clients/show", client)
    })

    // client new
    m.Get("/clients/new", func(r render.Render) {
        r.HTML(200, "clients/new", nil)
    })

    // client create
    m.Post("/clients", func(req *http.Request, r render.Render) {
        client := Client{
            FirstName: req.FormValue("first_name"),
            LastName: req.FormValue("last_name"),
            Email: req.FormValue("email"),
            Company: req.FormValue("company"),
            Project: req.FormValue("project"),
            Phone: req.FormValue("phone"),
        }
        client = createClient(client)
        r.HTML(201, "clients/create", client)
    })

	m.Run()
}
