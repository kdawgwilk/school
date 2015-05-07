'use strict';

var mongoose = require('mongoose'),
    Schema = mongoose.Schema;

var HighscoreSchema = new Schema({
  user_id: String,
  value: Number,
  updated: { type: Date, default: Date.now }
});

module.exports = mongoose.model('Highscore', HighscoreSchema);
