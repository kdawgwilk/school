<?php
require_once(dirname(__FILE__) . "/includes/auth.php");
require_once(dirname(__FILE__) . "/includes/header.php");
require_once(dirname(__FILE__) . "/includes/mysql.php");

?>

<div class="container">
    <?php if($current_user): ?>
        <h1>Welcome, <?= $user_row['first_name'] . " " . $user_row['last_name']; ?>!</h1>
    <?php else: ?>
        <h1>Welcome!</h1>
    <?php endif ?>

    <p>
        Today is <?php echo date('l jS \of F Y h:i:s A'); ?>
    </p>
    <table class="table">
        <?php
        $size = 12;
        for ($i = 0; $i < $size + 1; $i++) {
            echo "<tr>";
            for ($j = 0; $j < $size + 1; $j++) {
                if ($i == 0 && $j == 0) {
                    echo "<th></th>";
                } else if ($j == 0) {
                    echo "<th>$i</th>";
                } else if ($i == 0) {
                    echo "<th>$j</th>";
                } else {
                    $p = $i * $j;
                    echo "<td>$p</td>";
                }
            }
            echo "</tr>";
        }
        ?>
    </table>

</div>

<?php require_once(dirname(__FILE__) . "/includes/footer.php"); ?>
