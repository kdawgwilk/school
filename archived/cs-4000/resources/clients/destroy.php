<?php
require_once(dirname(__FILE__) . "/../../includes/mysql.php");

$id = mysqli_real_escape_string($connection, $_POST['id']);

$sql = "DELETE FROM clients WHERE id = $id";

mysqli_query($connection, $sql);

header("Location: /resources/clients/index.php");
die();
?>