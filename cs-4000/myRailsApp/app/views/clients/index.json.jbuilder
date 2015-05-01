json.array!(@clients) do |client|
  json.extract! client, :id, :first_name, :last_name, :email, :company, :project, :phone
  json.url client_url(client, format: :json)
end
