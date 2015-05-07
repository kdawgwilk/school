<?php
require_once(dirname(__FILE__) . "/../../includes/auth.php");
require_once(dirname(__FILE__) . "/../../includes/header.php");
require_once(dirname(__FILE__) . "/../../includes/mysql.php");

$id = mysqli_real_escape_string($connection, $_GET['id']);

$result = mysqli_query($connection, "SELECT * FROM clients WHERE id = $id");

$row = mysqli_fetch_array($result);
?>
<div class="container">
    <h1 class="text-center">Editing a Client</h1>
    <hr>
    <a href="/resources/clients/show.php?id=<?= $id ?>">Show Client</a>
    <a href="/resources/clients/index.php">Show all Clients</a>

    <form class="form-horizontal" method="post" action="/resources/clients/update.php">
        <div class="form-group">
            <label for="first_name" class="col-sm-offset-1 col-sm-2 control-label">First Name</label>
            <div class="col-sm-6">
                <input type="text" class="form-control" id="first_name" name="first_name" value="<?= $row['first_name'] ?>" placeholder="First Name">
            </div>
        </div>
        <div class="form-group">
            <label for="last_name" class="col-sm-offset-1 col-sm-2 control-label">Last Name</label>
            <div class="col-sm-6">
                <input type="text" class="form-control" id="last_name" name="last_name" value="<?= $row['last_name'] ?>" placeholder="Last Name">
            </div>
        </div>
        <div class="form-group">
            <label for="email" class="col-sm-offset-1 col-sm-2 control-label">Email</label>
            <div class="col-sm-6">
                <input type="email" class="form-control" id="email" name="email" value="<?= $row['email'] ?>" placeholder="Email">
            </div>
        </div>
        <div class="form-group">
            <label for="company" class="col-sm-offset-1 col-sm-2 control-label">Company</label>
            <div class="col-sm-6">
                <input type="text" class="form-control" id="company" name="company" value="<?= $row['company'] ?>" placeholder="Company">
            </div>
        </div>
        <div class="form-group">
            <label for="project" class="col-sm-offset-1 col-sm-2 control-label">Project</label>
            <div class="col-sm-6">
                <input type="text" class="form-control" id="project" name="project" value="<?= $row['project'] ?>" placeholder="Project">
            </div>
        </div>
        <div class="form-group">
            <label for="phone" class="col-sm-offset-1 col-sm-2 control-label">Phone #</label>
            <div class="col-sm-6">
                <input type="tel" class="form-control" id="phone" name="phone" value="<?= $row['phone'] ?>" placeholder="(XXX) XXX-XXXX">
            </div>
        </div>
        <div class="form-group">
            <div class="col-sm-offset-3 col-sm-6">
                <input type="hidden" name="id" value="<?= $row['id'] ?>">
                <a class="btn btn-default btn-lg btn-block" href="/resources/clients/index.php">Back</a>
                <button type="submit" class="btn btn-primary btn-lg btn-block">Submit</button>
            </div>
        </div>
    </form>
</div>

<?php require_once(dirname(__FILE__) . "/../../includes/footer.php"); ?>