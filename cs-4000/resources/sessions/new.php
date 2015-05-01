<?php
require_once(dirname(__FILE__) . "/../../includes/auth.php");
require_once(dirname(__FILE__) . "/../../includes/header.php");
require_once(dirname(__FILE__) . "/../../includes/mysql.php");

?>
<div class="container">
    <h1 class="text-center">Sign In</h1>
    <hr>
    <form class="form-horizontal" method="post" action="/resources/sessions/create.php">
        <div class="form-group">
            <label for="username" class="col-sm-offset-1 col-sm-2 control-label">Username or Email</label>
            <div class="col-sm-6">
                <input type="text" class="form-control" id="username" name="username" placeholder="Username or Email">
            </div>
        </div>
        <div class="form-group">
            <label for="password" class="col-sm-offset-1 col-sm-2 control-label">Password</label>
            <div class="col-sm-6">
                <input type="password" class="form-control" id="password" name="password" placeholder="Password">
            </div>
        </div>
        <div class="form-group">
            <div class="col-sm-offset-3 col-sm-6">
                <a class="btn btn-default btn-lg btn-block" href="/index.php">Back</a>
                <button type="submit" class="btn btn-primary btn-lg btn-block">Submit</button>
            </div>
        </div>
    </form>
</div>
<?php
require_once(dirname(__FILE__) . "/../../includes/footer.php");
?>
