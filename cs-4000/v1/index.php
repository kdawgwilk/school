<?php
require_once("vendor/autoload.php");
require_once("includes/DB.php");

function renderJSON($status_code, $response) {
    $app = \Slim\Slim::getInstance();
    $app->response->headers->set('Content-Type', 'application/json');
    $app->response->setStatus($status_code);
    echo json_encode($response);
}

$app = new \Slim\Slim();

//$app->hook('slim.before.dispatch', function () use ($app) {
//    $app->render('header.php');
//});
//
//$app->hook('slim.after.dispatch', function () use ($app) {
//    $app->render('footer.php');
//});

$app->get('/', function () {
    echo 'Welcome to Version 1 of my API';
});

$app->get('/swagger/', function () use ($app) {
    $app->render('swagger.json');
});

//clients index
$app->get('/clients/', function () use ($app) {
    $db = new DB();
    $clients = $db->getClients();
    $app->render('header.php');
	$app->render('clients/index.php', array(
        'clients' => $clients,
    ));
    $app->render('footer.php');
})->name("clients");
//clients index (json)
$app->get('/clients.json', function () use ($app) {
    $db = new DB();
    $clients = $db->getClients();
    renderJSON(200, $clients);
});//->name("clients");



// client show
$app->get('/clients/:id/', function ($id) use ($app) {
    $db = new DB();
    $client = $db->getClient($id);
    $app->render('header.php');
    $app->render('clients/show.php', array(
        'client' => $client,
        'client_url' => $app->urlFor('client', array('id' => $id))
    ));
    $app->render('footer.php');
})->conditions(array('id' => '\d+'))->name('client');
// client show (json)
$app->get('/clients/:id.json', function ($id) use ($app) {
    $db = new DB();
    $client = $db->getClient($id);
    renderJSON(200, $client);
})->conditions(array('id' => '\d+'));//->name('client');



//client new
$app->get('/clients/new/', function () use ($app) {
    $app->render('header.php');
    $app->render('clients/new.php', array(
        'client_url' => $app->urlFor('createClient')
    ));
    $app->render('footer.php');
});



//client create
$app->post('/clients/', function () use ($app) {
    $client = $app->request->post();
    $db = new DB();
    $db->createClient($client);
    $app->redirect($app->urlFor('clients'));
})->name('createClient');
//client create (json)
$app->post('/clients.json', function () use ($app) {
    $client = $app->request->post();
    $db = new DB();
    $new_client = $db->createClient($client);
    renderJSON(201, $new_client);
});



//client edit
$app->get('/clients/:id/edit/', function ($id) use ($app) {
    $db = new DB();
    $client = $db->getClient($id);
    $app->render('header.php');
    $app->render('clients/edit.php', array(
        'client' => $client,
        'client_url' => $app->urlFor('client', array('id' => $id))
    ));
    $app->render('footer.php');
})->conditions(array('id' => '\d+'));



//client update
$app->put('/clients/:id/', function ($id) use ($app) {
    $client = $app->request->post();
    $db = new DB();
    $db->updateClient($id, $client);
    $app->redirect($app->urlFor('client', array('id' => $id)));
})->conditions(array('id' => '\d+'));
//client update (json)
$app->put('/clients/:id.json', function ($id) use ($app) {
    $client = $app->request->get();
    $db = new DB();
    $db->updateClient($id, $client);
    renderJSON(200, $client);
})->conditions(array('id' => '\d+'));



//client destroy
$app->delete('/clients/:id/', function ($id) use ($app) {
    $db = new DB();
    $db->destroyClient($id);
    $app->redirect($app->urlFor('clients'));
})->conditions(array('id' => '\d+'));
//client destroy (json)
$app->delete('/clients/:id.json', function ($id) use ($app) {
    $db = new DB();
    $client = $db->getClient($id);
    $db->destroyClient($id);
    renderJSON(200, $client);
})->conditions(array('id' => '\d+'));



$app->run();
?>

