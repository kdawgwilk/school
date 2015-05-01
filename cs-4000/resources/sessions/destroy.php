<?php
require_once(dirname(__FILE__) . "/../../includes/auth.php");


session_destroy();

if (isset($_SESSION['user_id'])) {
    $form_valid = false;
} else {
    $form_valid = true;
}

header("Location: /index.php");
die();
?>

