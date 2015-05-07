var mongoose = require('mongoose');
var Schema   = mongoose.Schema;

var clientSchema = new Schema({	"first_name" : String,	"last_name" : String,	"email" : String,	"company" : String,	"project" : String,	"phone" : String});

module.exports = mongoose.model('client', clientSchema);