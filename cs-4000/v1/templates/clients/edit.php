<div class="container">
    <h1 class="text-center">Edit Client</h1>
    <hr>
    <form class="form-horizontal" method="post" action="<?= $client_url ?>">
        <div class="form-group">
            <label for="first_name" class="col-sm-offset-1 col-sm-2 control-label">First Name</label>
            <div class="col-sm-6">
                <input type="text" class="form-control" id="first_name" name="first_name" placeholder="First Name" value="<?= $client['first_name'] ?>">
            </div>
        </div>
        <div class="form-group">
            <label for="last_name" class="col-sm-offset-1 col-sm-2 control-label">Last Name</label>
            <div class="col-sm-6">
                <input type="text" class="form-control" id="last_name" name="last_name" placeholder="Last Name" value="<?= $client['last_name'] ?>">
            </div>
        </div>
        <div class="form-group">
            <label for="email" class="col-sm-offset-1 col-sm-2 control-label">Email</label>
            <div class="col-sm-6">
                <input type="email" class="form-control" id="email" name="email" placeholder="Email" value="<?= $client['email'] ?>">
            </div>
        </div>
        <div class="form-group">
            <label for="company" class="col-sm-offset-1 col-sm-2 control-label">Company</label>
            <div class="col-sm-6">
                <input type="text" class="form-control" id="company" name="company" placeholder="Company" value="<?= $client['email'] ?>">
            </div>
        </div>
        <div class="form-group">
            <label for="project" class="col-sm-offset-1 col-sm-2 control-label">Project</label>
            <div class="col-sm-6">
                <input type="text" class="form-control" id="project" name="project" placeholder="Project" value="<?= $client['project'] ?>">
            </div>
        </div>
        <div class="form-group">
            <label for="phone" class="col-sm-offset-1 col-sm-2 control-label">Phone #</label>
            <div class="col-sm-6">
                <input type="tel" class="form-control" id="phone" name="phone" placeholder="(XXX) XXX-XXXX" value="<?= $client['phone'] ?>">
            </div>
        </div>
        <div class="form-group">
            <div class="col-sm-offset-3 col-sm-6">
                <a class="btn btn-default btn-lg btn-block" href="<?= $client_url ?>">Back</a>
                <input type="hidden" name="_METHOD" value="PUT"/>
                <button type="submit" class="btn btn-primary btn-lg btn-block">Submit</button>
            </div>
        </div>
    </form>
</div>