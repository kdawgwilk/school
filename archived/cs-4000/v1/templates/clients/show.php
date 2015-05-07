<div class="container">
    <h1 class="text-center">Show Client</h1>
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
            <tr>
                <td><?= $client['first_name'] ?></td>
                <td><?= $client['last_name'] ?></td>
                <td><?= $client['email'] ?></td>
                <td><?= $client['company'] ?></td>
                <td><?= $client['project'] ?></td>
                <td><?= $client['phone'] ?></td>
                <td>
                    <a class="btn btn-primary btn-xs" href="/v1/clients/<?= $client['id'] ?>/edit">Edit</a>
                </td>
                <form method="post" action="<?= $client_url ?>">
                    <td>
                        <input type="hidden" name="_METHOD" value="DELETE"/>
                        <button type="submit" class="btn btn-danger btn-xs">Delete</button>
                    </td>
                </form>
            </tr>
        </tbody>
    </table>
</div>
