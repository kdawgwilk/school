<?php
require_once(dirname(__FILE__) . "/../../includes/mysql.php");

$id = mysqli_real_escape_string($connection, $_POST['id']);
$first_name = mysqli_real_escape_string($connection, $_POST['first_name']);
$last_name = mysqli_real_escape_string($connection, $_POST['last_name']);
$email = mysqli_real_escape_string($connection, $_POST['email']);
$company = mysqli_real_escape_string($connection, $_POST['company']);
$project = mysqli_real_escape_string($connection, $_POST['project']);
$phone = mysqli_real_escape_string($connection, $_POST['phone']);

$sql = "UPDATE clients SET first_name = '$first_name', last_name = '$last_name', email = '$email', company = '$company', project = '$project', phone = '$phone' WHERE id = '$id'";

$result = mysqli_query($connection, $sql);

header("Location: /resources/clients/show.php?id=$id");
die();
?>