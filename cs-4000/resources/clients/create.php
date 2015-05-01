<?php
require_once (dirname(__FILE__) . "/../../includes/mysql.php");

$first_name = mysqli_real_escape_string($connection, $_POST['first_name']);
$last_name = mysqli_real_escape_string($connection, $_POST['last_name']);
$email = mysqli_real_escape_string($connection, $_POST['email']);
$company = mysqli_real_escape_string($connection, $_POST['company']);
$project = mysqli_real_escape_string($connection, $_POST['project']);
$phone = mysqli_real_escape_string($connection, $_POST['phone']);

$sql = "INSERT INTO clients (first_name, last_name, email, company, project, phone) VALUES ('$first_name', '$last_name', '$email', '$company', '$project', '$phone')";

mysqli_query($connection, $sql);

//$to = "wilkinson.kaden@gmail.com";
//  $subject = "Test!";
//  $message = "Heres a test email!";
//  $headers = "From: kdawgwilk@gmail.com\r\n";
//
//mail($to, $subject, $message, $headers);


header("Location: /resources/clients/index.php");
die();
?>