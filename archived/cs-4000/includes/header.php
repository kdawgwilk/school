<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="CS-4000">
    <meta name="author" content="Kaden Wilkinson">
    <title>CS-4000</title>
    <script type="text/javascript" src="/bower_components/jquery/dist/jquery.min.js"></script>
    <script type="text/javascript" src="/bower_components/angular/angular.min.js"></script>

    <!-- Latest compiled and minified JavaScript -->
    <script src="/bower_components/bootstrap/dist/js/bootstrap.min.js"></script>
    <script type="text/javascript" src="/src/js/main.js"></script>

    <!-- Latest compiled and minified CSS -->
    <link rel="stylesheet" href="/bower_components/bootstrap/dist/css/bootstrap.min.css">
    <link rel="stylesheet" type="text/css" href="/src/css/style.css">
</head>
<body>
<header>
    <nav id="navbar-scroll" class="hidden-xs navbar navbar-default navbar-fixed-top" role="navigation">
        <div class="container-fluid">
            <div class="navbar-header">
                <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
                <a class="navbar-brand logo" href="/">CS-4000</a>
            </div>
            <div id="navbar" class="collapse navbar-collapse">
                <ul class="nav navbar-nav">
                    <li><a href ="/index.php">Home</a></li>
                    <li><a href ="/about.php">About</a></li>
                    <li><a href ="/contact.php">Contact</a></li>
                    <li class="dropdown">
                        <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-expanded="false">Uploads <span class="caret"></span></a>
                        <ul class="dropdown-menu" role="menu">
                            <li><a href="/uploads/index.php">All My Uploads</a></li>
                            <li><a href="/uploads/new.php">New Upload</a></li>
                        </ul>
                    </li>
                    <li class="dropdown">
                        <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-expanded="false">Clients <span class="caret"></span></a>
                        <ul class="dropdown-menu" role="menu">
                            <li><a href="/resources/clients/index.php">All Clients</a></li>
                            <li><a href="/resources/clients/new.php">New Client</a></li>
                            <li><a href="#">Something else here</a></li>
<!--                            <li class="divider"></li>-->
<!--                            <li class="dropdown-header">Nav header</li>-->
<!--                            <li><a href="#">Separated link</a></li>-->
<!--                            <li><a href="#">One more separated link</a></li>-->
                        </ul>
                    </li>
                    <?php if ($user_row['role'] > 3): ?>
                    <li class="dropdown">
                        <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-expanded="false">Users <span class="caret"></span></a>
                        <ul class="dropdown-menu" role="menu">
                            <li><a href="/resources/users/admin/index.php">All Users</a></li>
                        </ul>
                    </li>
                    <?php endif ?>
                </ul>
                <ul class="nav navbar-nav navbar-right">
                    <?php if ($current_user): ?>
                    <li>
                        <a href="#">
                            Welcome,
                            <?= $user_row['first_name'] . " " . $user_row['last_name']; ?>
                        </a>
                    </li>
                    <?php else: ?>
                    <li>
                        <form class="navbar-form navbar-right" role="sign_up">
                            <a href="/resources/users/new.php"><button type="button" class="btn btn-default">Sign up</button></a>
                        </form>
                    </li>
                    <?php endif ?>
                    <li>
                        <form class="navbar-form navbar-right" role="login">
                            <a href="/resources/sessions/<?php if($current_user){echo "destroy";}else{echo "new";} ?>.php"><button type="button" class="btn btn-default"><?php if($current_user){echo "Logout";}else{echo "Login";} ?></button></a>
                        </form>
                    </li>
                </ul>
            </div>
        </div>
    </nav>
</header>
<?php
require_once(dirname(__FILE__) . "/errors.php");
?>