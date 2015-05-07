var express = require('express');
var router = express.Router();

exports.getClients = function(req, res, next) {
  req.db.clients.find({
    completed: false
  }).toArray(function(error, clients){
    if (error) {
      return next(error);
    }
    res.render('clients', {
      title: 'All Clients',
      clients: clients || []
    });
  });
};

exports.getClient = function(req, res, next) {
  req.db.clients.findById(req.client._id, function(error, clients){
    if (error) {
      return next(error);
    }
    res.render('clients/:id', {
      title: 'All Clients',
      client: client || []
    });
  });
};

exports.createClient = function(req, res, next){
  if (!req.body ||
      !req.body.first_name ||
      !req.body.last_name ||
      !req.body.email ||
      !req.body.company ||
      !req.body.project ||
      !req.body.phone) {
    return next(new Error('No data provided.'));
  }
  req.db.clients.save({
    first_name: req.body.first_name,
    last_name: req.body.last_name,
    email: req.body.email,
    company: req.body.company,
    project: req.body.project,
    phone: req.body.phone,
    completed: false
  }, function(error, client){
    if (error) {
      return next(error);
    }
    if (!client) {
      return next(new Error('Failed to save.'));
    }
    console.info('Added %s with id=%s', client.first_name, client._id);
    res.redirect('/clients');
  })
};

exports.updateClient = function(req, res, next){
  if (!req.body ||
      !req.body.first_name ||
      !req.body.last_name ||
      !req.body.email ||
      !req.body.company ||
      !req.body.project ||
      !req.body.phone) {
    return next(new Error('No data provided.'));
  }
  req.db.clients.save({
    first_name: req.body.first_name,
    last_name: req.body.last_name,
    email: req.body.email,
    company: req.body.company,
    project: req.body.project,
    phone: req.body.phone,
    completed: false
  }, function(error, client){
    if (error) {
      return next(error);
    }
    if (!client) {
      return next(new Error('Failed to save.'));
    }
    console.info('Added %s with id=%s', client.first_name, client._id);
    res.redirect('/clients/:id', client._id);
  })
};

exports.deleteClient = function(req, res, next) {
  req.db.clients.removeById(req.client._id, function(error, count) {
    if (error) {
      return next(error);
    }
    if (count !==1) {
      return next(new Error('Something went wrong.'));
    }
    console.info('Deleted client %s with id=%s completed.',
        req.client.name,
        req.client._id);
    res.send(200);
  });
};


// ALL clients
router.get('/', function(req, res, next) {
  var clients = '';
  res.render('clients/index', {
    clients: clients
  });
});



// SHOW client
router.get('/:id', function(req, res, next) {
  var client = '';
  res.render('clients/show', {
    client: client
  });
});



// EDIT client
router.get('/:id/edit', function(req, res, next) {
  var client = '';
  res.render('clients/edit', {
    client: client
  });
});



// NEW client
router.get('/new', function(req, res, next) {
  res.render('clients/new', {});
});

module.exports = router;
