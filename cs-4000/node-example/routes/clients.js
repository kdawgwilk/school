var express = require('express');
var router = express.Router();
var methodOverride = require('method-override');
var controller = require('../controllers/clientController.js');

router.use(methodOverride(function(req, res){
    if (req.body && typeof req.body === 'object' && '_method' in req.body) {
        // look in urlencoded POST bodies and delete it
        var method = req.body._method;
        delete req.body._method;
        return method;
    }
}));

/*
 * GET All Clients
 */
router.get('/', function(req, res) {
    controller.list(req, res);
});

/*
 * GET New Client
 */
router.get('/new', function(req, res) {
    res.render('clients/new');
});

/*
 * GET Show Client
 */
router.get('/:id', function(req, res) {
    controller.show(req, res);
});

/*
 * POST Create Client
 */
router.post('/', function(req, res) {
    controller.create(req, res);
});

/*
 * GET Edit Client
 */
router.get('/:id/edit', function(req, res) {
    controller.edit(req, res);
});

/*
 * PUT Update Client
 */
router.put('/:id', function(req, res) {
    controller.update(req, res);
});

/*
 * DELETE Destroy Client
 */
router.delete('/:id', function(req, res) {
    controller.remove(req, res);
});

module.exports = router;