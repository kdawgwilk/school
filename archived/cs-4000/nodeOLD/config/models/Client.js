var mongoose = require('mongoose'),
    Schema = mongoose.Schema;

// client model
var clientSchema = new Schema({
    first_name: String,
    last_name: String,
    email: String,
    company: String,
    project: String,
    phone: String,
    updated_at: { type: Date, default: Date.now }
});

mongoose.model('Client', clientSchema);