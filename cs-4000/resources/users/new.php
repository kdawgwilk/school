<?php
require_once(dirname(__FILE__) . "/../../includes/header.php");
require_once(dirname(__FILE__) . "/../../includes/mysql.php");


?>

<div class="container">
    <h1 class="text-center">New User</h1>
    <hr>
    <form class="form-horizontal" method="post" action="/resources/users/create.php">
        <div class="form-group <?php if($errors['first_name']){echo "has-error has-feedback";} ?>">
            <label for="first_name" class="col-sm-offset-1 col-sm-2 control-label">First Name</label>
            <div class="col-sm-6">
                <input type="text" class="form-control" id="first_name" name="first_name" placeholder="First Name" value="<?= $first_name ?>">
                <span class="<?php if(!$errors['first_name']){echo "hidden";} ?> glyphicon glyphicon-remove form-control-feedback" aria-hidden="true"></span>
                <span id="first_name_error" class="sr-only">(success)</span>
                <span id="helpBlock" class="help-block"><?= $errors['first_name'] ?></span>
            </div>
        </div>
        <div class="form-group <?php if($errors['last_name']){echo "has-error has-feedback";} ?>">
            <label for="last_name" class="col-sm-offset-1 col-sm-2 control-label">Last Name</label>
            <div class="col-sm-6">
                <input type="text" class="form-control" id="last_name" name="last_name" placeholder="Last Name" value="<?= $last_name ?>">
                <span class="<?php if(!$errors['last_name']){echo "hidden";} ?> glyphicon glyphicon-remove form-control-feedback" aria-hidden="true"></span>
                <span id="first_name_error" class="sr-only">(success)</span>
                <span id="helpBlock" class="help-block"><?= $errors['last_name'] ?></span>
            </div>
        </div>
        <div class="form-group <?php if($errors['username']){echo "has-error has-feedback";} ?>">
            <label for="username" class="col-sm-offset-1 col-sm-2 control-label">Username</label>
            <div class="col-sm-6">
                <input type="text" class="form-control" id="username" name="username" placeholder="Username" value="<?= $username ?>">
                <span class="<?php if(!$errors['username']){echo "hidden";} ?> glyphicon glyphicon-remove form-control-feedback" aria-hidden="true"></span>
                <span id="first_name_error" class="sr-only">(success)</span>
                <span id="helpBlock" class="help-block"><?= $errors['username'] ?></span>
            </div>
        </div>
        <div class="form-group <?php if($errors['email']){echo "has-error has-feedback";} ?>">
            <label for="email" class="col-sm-offset-1 col-sm-2 control-label">Email</label>
            <div class="col-sm-6">
                <input type="email" class="form-control" id="email" name="email" placeholder="Email" value="<?= $email ?>">
                <span class="<?php if(!$errors['email']){echo "hidden";} ?> glyphicon glyphicon-remove form-control-feedback" aria-hidden="true"></span>
                <span id="first_name_error" class="sr-only">(success)</span>
                <span id="helpBlock" class="help-block"><?= $errors['email'] ?></span>
            </div>
        </div>

        <div class="form-group <?php if($errors['password']){echo "has-error has-feedback";} ?>">
            <label for="password" class="col-sm-offset-1 col-sm-2 control-label">Password</label>
            <div class="col-sm-6">
                <input type="password" class="form-control" id="password" name="password" placeholder="Password">
                <span class="<?php if(!$errors['password']){echo "hidden";} ?> glyphicon glyphicon-remove form-control-feedback" aria-hidden="true"></span>
                <span id="first_name_error" class="sr-only">(success)</span>
                <span id="helpBlock" class="help-block"><?= $errors['password'] ?></span>
            </div>
        </div>
        <div class="form-group <?php if($errors['confirm_password']){echo "has-error has-feedback";} ?>">
            <label for="confirm_password" class="col-sm-offset-1 col-sm-2 control-label">Confirm Password</label>
            <div class="col-sm-6">
                <input type="password" class="form-control" id="confirm_password" name="confirm_password" placeholder="Confirm Password">
                <span class="<?php if(!$errors['confirm_password']){echo "hidden";} ?> glyphicon glyphicon-remove form-control-feedback" aria-hidden="true"></span>
                <span id="first_name_error" class="sr-only">(success)</span>
                <span id="helpBlock" class="help-block"><?= $errors['confirm_password'] ?></span>
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
