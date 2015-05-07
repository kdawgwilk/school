<?php
require_once(dirname(__FILE__) . "/../../includes/auth.php");
require_once(dirname(__FILE__) . "/../../includes/header.php");
require_once(dirname(__FILE__) . "/../../includes/mysql.php");

$id = $_GET['id'];

$result = mysqli_query($connection, "SELECT * FROM clients WHERE id = $id");

$row = mysqli_fetch_array($result);

?>
<div class="container">
    <h1 class="text-center">Showing a Client</h1>
    <hr>


    <?php if ($row): ?>
        <table class="table">
            <tr>
                <th>First Name:</th>
                <td><?= $row['first_name'] ?></td>
            </tr>
            <tr>
                <th>Last Name:</th>
                <td><?= $row['last_name'] ?></td>
            </tr>
            <tr>
                <th>Email:</th>
                <td><?= $row['email'] ?></td>
            </tr>
            <tr>
                <th>Company:</th>
                <td><?= $row['company'] ?></td>
            </tr>
            <tr>
                <th>Project:</th>
                <td><?= $row['project'] ?></td>
            </tr>
            <tr>
                <th>Phone:</th>
                <td><?= $row['phone'] ?></td>
            </tr>
        </table>
        <a class="btn btn-default btn-lg" href="/resources/clients/index.php">All Clients</a>
        <a class="btn btn-primary btn-lg" href="/resources/clients/edit.php?id=<?= $id ?>">Edit Client</a>
    <?php else: ?>
        <h1 class="text-center">No Student Found!</h1>
        <hr>
        <a href="/resources/clients/index.php">All Clients</a>
    <?php endif ?>
</div>

<?php require_once(dirname(__FILE__) . "/../../includes/footer.php"); ?>