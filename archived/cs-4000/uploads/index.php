<?php
require_once(dirname(__FILE__) . "/../includes/auth.php");
require_once(dirname(__FILE__) . "/../includes/header.php");

//$user_id = $current_user['id'];
$sql = "SELECT * FROM uploads WHERE user_id = '$user_id'";

$result = mysqli_query($connection, $sql);

?>
<div class="container">
    <h1 class="text-center">All Uploads</h1>
    <hr>
    <?php while ($row = mysqli_fetch_array($result)): ?>
        <img src="files/<?= $row['id'] ?>/<?= $row['original_filename'] ?>"/>
    <?php endwhile ?>
</div>
