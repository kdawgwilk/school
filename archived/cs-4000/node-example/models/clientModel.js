var mongoose = require('mongoose');
var Schema   = mongoose.Schema;

var clientSchema = new Schema({

module.exports = mongoose.model('client', clientSchema);