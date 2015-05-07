var model = require('../models/clientModel.js');

/**
 * clientController.js
 *
 * @description :: Server-side logic for managing clients.
 */
module.exports = {

    /**
     * clientController.list()
     */
    list: function(req, res) {
        model.find(function(err, clients){
            if(err) {
                return res.json(500, {
                    message: 'Error getting clients.'
                });
            }
            res.format({
                html: function() {
                    res.render('clients/index', {
                        'clients': clients
                    })
                },
                json: function() {
                    res.json(clients);
                }
            });
        });
    },

    /**
     * clientController.show()
     */
    show: function(req, res) {
        var id = req.params.id;
        model.findOne({_id: id}, function(err, client){
            if(err) {
                return res.json(500, {
                    message: 'Error getting client.'
                });
            }
            if(!client) {
                return res.json(404, {
                    message: 'No such client'
                });
            }
            res.format({
                html: function() {
                    res.render('clients/show', {
                        'client': client
                    })
                },
                json: function() {
                    res.json(client);
                }
            });
        });
    },

    /**
     * clientController.create()
     */
    create: function(req, res) {
        var client = new model({
			first_name : req.body.first_name,
			last_name : req.body.last_name,
			email : req.body.email,
			company : req.body.company,
			project : req.body.project,
			phone : req.body.phone
        });

        client.save(function(err, client){
            if(err) {
                return res.json(500, {
                    message: 'Error saving client',
                    error: err
                });
            }
            res.format({
                html: function() {
                    res.location("clients");
                    res.redirect('/clients');
                },
                json: function() {
                    res.json(client);
                }
            });
        });
    },

    /**
     * clientController.edit()
     */
    edit: function(req, res) {
        var id = req.params.id;
        model.findOne({_id: id}, function(err, client){
            if(err) {
                return res.json(500, {
                    message: 'Error getting client.'
                });
            }
            if(!client) {
                return res.json(404, {
                    message: 'No such client'
                });
            }
            res.format({
                html: function() {
                    res.render('clients/edit', {
                        'client': client
                    })
                },
                json: function() {
                    res.json(client);
                }
            });
        });
    },

    /**
     * clientController.update()
     */
    update: function(req, res) {
        var id = req.params.id;
        model.findOne({_id: id}, function(err, client){
            if(err) {
                return res.json(500, {
                    message: 'Error saving client',
                    error: err
                });
            }
            if(!client) {
                return res.json(404, {
                    message: 'No such client'
                });
            }

            client.first_name =  req.body.first_name ? req.body.first_name : client.first_name;
			client.last_name =  req.body.last_name ? req.body.last_name : client.last_name;
			client.email =  req.body.email ? req.body.email : client.email;
			client.company =  req.body.company ? req.body.company : client.company;
			client.project =  req.body.project ? req.body.project : client.project;
			client.phone =  req.body.phone ? req.body.phone : client.phone;
			
            client.save(function(err, client){
                if(err) {
                    return res.json(500, {
                        message: 'Error getting client.'
                    });
                }
                if(!client) {
                    return res.json(404, {
                        message: 'No such client'
                    });
                }
                res.format({
                    html: function() {
                        res.redirect('/clients/' + client._id);
                    },
                    json: function() {
                        res.json(client);
                    }
                });
            });
        });
    },

    /**
     * clientController.remove()
     */
    remove: function(req, res) {
        var id = req.params.id;
        model.findByIdAndRemove(id, function(err, client){
            if(err) {
                return res.json(500, {
                    message: 'Error getting client.'
                });
            }
            res.format({
                html: function() {
                    res.redirect('/clients');
                },
                json: function() {
                    res.json(client);
                }
            });
        });
    }
};