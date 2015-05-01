<?php
require_once(dirname(__FILE__) . "/../../includes/header.php");
require_once(dirname(__FILE__) . "/../../includes/mysql.php");

$first_name = mysqli_real_escape_string($connection, $_POST['first_name']);
$last_name  = mysqli_real_escape_string($connection, $_POST['last_name']);
$username   = mysqli_real_escape_string($connection, $_POST['username']);
$email      = mysqli_real_escape_string($connection, $_POST['email']);
$password   = $_POST['password'];
$confirm_password   = $_POST['confirm_password'];

$errors = [];

if (strlen($first_name) < 1) {
    $errors['first_name'] = "Cannot be left blank!";
}
if (strlen($last_name) < 1) {
//    $errors['last'] = "Last name was empty!";
    $errors['last_name'] = "Cannot be left blank!";
}
if (strlen($username) < 5) {
    $errors['username'] = "Username needs to be at least 5 characters long!";
}
if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
    $errors['email'] = "Please enter a valid email!";
}
if (strlen($password) < 6) {
    $errors['password'] = "Your Password must be at least 6 characters long!";
}
if ($password != $confirm_password) {
    $errors['confirm_password'] = "Passwords don't match!";
}

$form_valid = count($errors) == 0;

if ($form_valid) {
    $encrypted_password = password_hash($password, PASSWORD_BCRYPT);
    mysqli_query($connection, "INSERT INTO users (first_name, last_name, username, email, encrypted_password) VALUES ('$first_name', '$last_name', '$username', '$email', '$encrypted_password')");
//    $errors['mysql'] = mysqli_error($connection);
}

$form_valid = count($errors) == 0;
?>

<div class="container">
    <?php if ($form_valid): ?>

        <div class="alert alert-success alert-dismissible" role="alert">
            <button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>
            <strong>Success!</strong> Your signed up!
        </div>

    <?php else: ?>

        <div class="alert alert-danger alert-dismissible" role="alert">
            <button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>
            <strong>Error!</strong> There was a problem with your form!
        </div>

        <?php require_once(dirname(__FILE__) . "/new.php"); ?>

    <?php endif ?>
</div>



<?php
require_once(dirname(__FILE__) . "/../../includes/header.php");
?>