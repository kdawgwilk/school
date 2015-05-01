<?php
require_once(dirname(__FILE__) . "/includes/auth.php");
require_once(dirname(__FILE__) . "/includes/header.php");
require_once(dirname(__FILE__) . "/includes/mysql.php");
?>
<div class="container">
    <h1 class="text-center">Contact Us</h1>
    <hr>
    <form class="form-horizontal" method="post" action="/submit.php">
        <div class="form-group">
            <label for="name" class="col-sm-offset-1 col-sm-2 control-label">Name</label>
            <div class="col-sm-6">
                <input type="text" class="form-control" id="name" name="name" placeholder="Name">
            </div>
        </div>
        <div class="form-group">
            <label for="email" class="col-sm-offset-1 col-sm-2 control-label">Email</label>
            <div class="col-sm-6">
                <input type="email" class="form-control" id="email" name="email" placeholder="Email">
            </div>
        </div>
        <div class="form-group">
            <label for="comment" class="col-sm-offset-1 col-sm-2 control-label">Comment</label>
            <div class="col-sm-6">
                <textarea class="form-control" id="comment" name="comment" rows="4"></textarea>
            </div>
        </div>
    </form>
</div>


<?php require_once(dirname(__FILE__) . "/includes/footer.php"); ?>
