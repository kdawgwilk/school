<?php
require_once(dirname(__FILE__) . "/../includes/auth.php");
require_once(dirname(__FILE__) . "/../includes/header.php");

$title = mysqli_real_escape_string($connection, $_POST['title']);
$file_name = mysqli_real_escape_string($connection, $_FILES['file']['name']);
$file_size = mysqli_real_escape_string($connection, $_FILES['file']['size']);
$file_type = mysqli_real_escape_string($connection, $_FILES['file']['type']);
$file_tmp_name = $_FILES['file']['tmp_name'];
$file_error = $_FILES['file']['error'];
// check for errors and add to errors array

$errors = [];

if (strlen($title) < 1) {
    $errors['title'] = "You need to include a title";
}
if (!in_array($file_type, ["image/jpeg","image/jpg", "image/png"])) {
    $errors['file'] = "Uploaded file must be a JPG or PNG";
}
if ($file_size > 1024*1024) {
    $errors['file'] = "Uploaded file must not be larger than 1MB";
}

$form_valid = count($errors) == 0;

if ($form_valid) {
    if ($current_user) {
//        $user_id = $current_user['id'];
    }
    $sql = "INSERT INTO uploads (original_filename, file_size, file_type, user_id, title, uploaded_at) VALUES ('$file_name', '$file_size', '$file_size', '$user_id', '$title', NOW());";
    mysqli_query($connection, $sql);
    if ($mysql_error = mysqli_error($connection)) {
        $errors['sql'] = $mysql_error;
    } else {
        $upload_id = mysqli_insert_id($connection);
        $new_file_dir = "files/$upload_id";
        $new_file_path = "$new_file_dir/$file_name";
        mkdir($new_file_dir, 0755, true);
        chmod($new_file_dir, 0755);
        move_uploaded_file($file_tmp_name, $new_file_path);
        chmod($new_file_path, 0644);
    }
}
$form_valid = count($errors) == 0;


?>

<?php if ($form_valid): ?>

<div class="container">
    <h1>Upload</h1>
    <hr>
    <ul>
        <li><?= $title ?></li>
        <li><?= $file_name ?></li>
        <li><?= $file_size ?></li>
        <li><?= $file_type ?></li>
        <li><?= $file_tmp_name ?></li>
    </ul>
</div>
<?php else: ?>
    <div class="container">
        <?php require_once(dirname(__FILE__) . "/new.php") ?>
    </div>
<?php endif ?>

<?php require_once(dirname(__FILE__) . "/../includes/footer.php"); ?>