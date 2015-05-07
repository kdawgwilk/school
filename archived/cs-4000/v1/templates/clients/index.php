<div class="container">
    <h1 class="text-center">All Clients</h1>
    <hr>

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
        </tr>
        </thead>
        <tbody>
        <?php foreach($clients as $client): ?>
            <tr>
                <td><?= $client['first_name'] ?></td>
                <td><?= $client['last_name'] ?></td>
                <td><?= $client['email'] ?></td>
                <td><?= $client['company'] ?></td>
                <td><?= $client['project'] ?></td>
                <td><?= $client['phone'] ?></td>
                <td>
                    <a class="btn btn-default btn-xs" href="/v1/clients/<?= $client['id'] ?>">Show</a>
                </td>
                <td>
                    <a class="btn btn-primary btn-xs" href="/v1/clients/<?= $client['id'] ?>/edit">Edit</a>
                </td>
            </tr>
        <?php endforeach ?>
        </tbody>
    </table>
</div>
