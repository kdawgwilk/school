<?php
require_once(dirname(__FILE__) . "/../../includes/auth.php");

$username = mysqli_real_escape_string($connection, $_POST['username']);
$password  = $_POST['password'];

$result = mysqli_query($connection, "SELECT * FROM users WHERE email = '$username' OR username = '$username'");
$row = mysqli_fetch_array($result);

if (strlen($username) == 0 ||
    strlen($password)  == 0) {
    $form_valid = false;
} else {
    if (password_verify($password, $row['encrypted_password'])) {
        $form_valid = true;
        $_SESSION['user_id'] = $row['id'];
    } else {
        $form_valid = false;
    }
    mysqli_query($connection, "INSERT INTO users (first_name, last_name, username, email, encrypted_password) VALUES ('$first_name', '$last_name', '$username', '$email', '$encrypted_password')");
}

header("Location: /index.php");
die();

?>
