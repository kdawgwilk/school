<?php
require_once(dirname(__FILE__) . "/../includes/auth.php");
require_once(dirname(__FILE__) . "/../includes/header.php");
?>
<div class="container">
    <h1 class="text-center">New Upload</h1>
    <hr>
    <form class="form-horizontal" method="post" action="/uploads/create.php" enctype="multipart/form-data">
        <div class="form-group <?php if($errors['title']){echo "has-error has-feedback";} ?>">
            <label for="title" class="col-sm-offset-1 col-sm-2 control-label">Title</label>
            <div class="col-sm-6">
                <input type="text" class="form-control" id="title" name="title" placeholder="Title" value="<?= $title ?>">
                <span class="<?php if(!$errors['title']){echo "hidden";} ?> glyphicon glyphicon-remove form-control-feedback" aria-hidden="true"></span>
                <span id="first_name_error" class="sr-only">(success)</span>
                <span id="helpBlock" class="help-block"><?= $errors['title'] ?></span>
            </div>
        </div>
        <div class="form-group <?php if($errors['file']){echo "has-error has-feedback";} ?>"">
            <label for="file" class="col-sm-offset-1 col-sm-2 control-label">File to Upload</label>
            <div class="col-sm-6">
                <input type="file" class="form-control" id="file" name="file">
                <span class="<?php if(!$errors['file']){echo "hidden";} ?> glyphicon glyphicon-remove form-control-feedback" aria-hidden="true"></span>
                <span id="first_name_error" class="sr-only">(success)</span>
                <span id="helpBlock" class="help-block"><?= $errors['file'] ?></span>
            </div>
        </div>
        <div class="form-group">
            <div class="col-sm-offset-3 col-sm-6">
                <a class="btn btn-default btn-lg btn-block" href="/resources/clients/index.php">Back</a>
                <button type="submit" class="btn btn-primary btn-lg btn-block">Submit</button>
            </div>
        </div>
    </form>
</div>

<?php require_once(dirname(__FILE__) . "/../includes/footer.php"); ?>