<?php
session_start();
require_once(dirname(__FILE__) . "/mysql.php");

if (isset($_SESSION['user_id'])) {
    $current_user = true;
    $user_id = $_SESSION['user_id'];

    $user_query = mysqli_query($connection, "SELECT * FROM users WHERE id = '$user_id'");

    $user_row = mysqli_fetch_array($user_query);
} else {
    $current_user = false;
}

?>