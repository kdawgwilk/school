var mongoose = require('mongoose'),
    Client = mongoose.model('Client');

module.exports = {
    index: function(req, res){
        Client.find({}, function(err, clients){
            if(err) res.send(err);
            res.json(clients);
        })
    },
    show: function(req, res){
        console.log('Viewing ' + req.params.id);
    },
    create: function(req, res){
        console.log('Todo created')
    },
    destroy: function(req, res){
        console.log('Todo deleted')
    },
    update: function(req, res){
        console.log('Todo ' + req.params.id + ' updated')
    }
};