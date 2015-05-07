var express = require('express');
var path = require('path');
var favicon = require('serve-favicon');
var logger = require('morgan');
var cookieParser = require('cookie-parser');
var bodyParser = require('body-parser');
var port = 3000;

var mongoose = require('mongoose');

var app = express();

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'jade');

//app.use(favicon(__dirname + '/public/favicon.ico'));
app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded());
app.use(cookieParser());
// telling Express to serve static objects from /public
app.use(express.static(path.join(__dirname, 'public')));


require('./config/models/Client');
mongoose.connect('mongodb://localhost/client', function(){
  console.log('Connected to database!')
});


// Routes
var main = require('./routes/index');
var clients = require('./routes/clients');
var clientRouter = express.Router();
app.use('/clients', clientRouter);

app.get('/', main);
clientRouter.get('/', clients.index);
clientRouter.get('/:id', clients.show);
clientRouter.get('/new', clients.new);
clientRouter.post('/', clients.create);
clientRouter.put('/:id', clients.update);
clientRouter.delete('/:id', clients.destroy);

// Start server
app.listen(port, function(){
  console.log('Server listening on port ' + port)
});

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  var err = new Error('Not Found');
  err.status = 404;
  next(err);
});

// error handlers

// development error handler
// will print stacktrace
//if (app.get('env') === 'development') {
//  app.use(function(err, req, res, next) {
//    res.status(err.status || 500);
//    res.render('error', {
//      message: err.message,
//      error: err
//    });
//  });
//}

// production error handler
// no stacktraces leaked to user
//app.use(function(err, req, res, next) {
//  res.status(err.status || 500);
//  res.render('error', {
//    message: err.message,
//    error: {}
//  });
//});


module.exports = app;
