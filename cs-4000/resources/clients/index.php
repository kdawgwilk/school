<?php
require_once(dirname(__FILE__) . "/../../includes/auth.php");
require_once(dirname(__FILE__) . "/../../includes/header.php");

if (isset($_GET['website']) && $_GET['website'] == "true") {
    $sql = "SELECT * FROM clients WHERE project = 'Website'";
} elseif (isset($_GET['sort_first']) && $_GET['sort_first'] == "true") {
    $sql = "SELECT * FROM clients ORDER BY first_name ASC";
} else {
    $sql = "SELECT * FROM clients";
}
$result = mysqli_query($connection, $sql);

?>
<div class="container">
    <h1 class="text-center">All Clients</h1>
    <hr>
    <a href="/resources/clients/index.php">Show all Clients </a>|
    <a href="/resources/clients/index.php?sort_first=true">Sort by First Name </a>|
    <a href="/resources/clients/index.php?website=true">Show Website Projects</a>

    <table class="table">
        <thead>
        <tr>
            <th>First Name</th>
            <th>Last Name</th>
            <th>Email</th>
            <th>Company</th>
            <th>Project</th>
            <th>Phone</th>
            <th></th>
            <th></th>
            <th></th>
        </tr>
        </thead>
        <tbody>
        <?php while ($row = mysqli_fetch_array($result)): ?>
            <tr>
                <td><?= $row['first_name'] ?></td>
                <td><?= $row['last_name'] ?></td>
                <td><?= $row['email'] ?></td>
                <td><?= $row['company'] ?></td>
                <td><?= $row['project'] ?></td>
                <td><?= $row['phone'] ?></td>
                <td>
                    <a class="btn btn-primary btn-xs" href="/resources/clients/show.php?id=<?= $row['id'] ?>">Show</a>
                </td>
                <td>
                    <a class="btn btn-default btn-xs" href="/resources/clients/edit.php?id=<?= $row['id'] ?>">Edit</a>
                </td>
                <td>
                    <form method="post" action="/resources/clients/destroy.php">
                        <input type="hidden" name="id" value="<?= $row['id'] ?>">
                        <input class="btn btn-danger btn-xs" type="submit" value="Destroy">
                    </form>
                </td>
            </tr>
        <?php endwhile ?>
        </tbody>
    </table>
    <a class="btn btn-primary btn-lg" href="/resources/clients/new.php">New Client</a>
</div>

<?php require_once(dirname(__FILE__) . "/../../includes/footer.php"); ?>