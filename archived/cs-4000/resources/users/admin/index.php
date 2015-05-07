<?php
require_once(dirname(__FILE__) . "/../../../includes/auth.php");
require_once(dirname(__FILE__) . "/../../../includes/header.php");

$result = mysqli_query($connection, "SELECT * FROM users");

?>
<?php if ($user_row['role'] > 3): ?>
<div class="container">
    <h1 class="text-center">All Users</h1>
    <hr>

    <table class="table">
        <thead>
        <tr>
            <th>First Name</th>
            <th>Last Name</th>
            <th>Username</th>
            <th>Email</th>
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
                <td><?= $row['username'] ?></td>
                <td><?= $row['email'] ?></td>
                <td>
                    <a class="btn btn-primary btn-xs" href="/resources/users/show.php?id=<?= $row['id'] ?>">Show</a>
                </td>
                <td>
                    <a class="btn btn-default btn-xs" href="/resources/users/edit.php?id=<?= $row['id'] ?>">Edit</a>
                </td>
                <td>
                    <form method="post" action="/resources/users/destroy.php">
                        <input type="hidden" name="id" value="<?= $row['id'] ?>">
                        <input class="btn btn-danger btn-xs" type="submit" value="Destroy">
                    </form>
                </td>
            </tr>
        <?php endwhile ?>
        </tbody>
    </table>
    <a class="btn btn-primary btn-lg" href="/resources/users/new.php">New User</a>
    <?php else: ?>
        <h1>You can't access this page!</h1>
    <?php endif ?>
</div>

<?php
require_once(dirname(__FILE__) . "/../../../includes/footer.php");
?>
