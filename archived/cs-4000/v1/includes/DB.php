<?php
class DB {

    private $connection;

    function __construct() {
        $this->connection = new PDO("mysql:host=trendlycreations.cpqwlpe3owti.us-west-2.rds.amazonaws.com;dbname=trendly","kdawgwilk","123Wilkinson123");
    }

    function createClient($client) {
        $sql = "INSERT INTO clients (first_name, last_name, email, company, project, phone) VALUES (:first_name, :last_name, :email, :company, :project, :phone)";
        $stmt = $this->connection->prepare($sql);
        $stmt->bindParam('first_name', $client['first_name']);
        $stmt->bindParam('last_name', $client['last_name']);
        $stmt->bindParam('email', $client['email']);
        $stmt->bindParam('company', $client['company']);
        $stmt->bindParam('project', $client['project']);
        $stmt->bindParam('phone', $client['phone']);
        $stmt->execute();
        $client['id'] = $this->connection->lastInsertId();;
        return $client;
    }

    function getClients() {
        $sql = "SELECT * FROM clients";
        $stmt = $this->connection->prepare($sql);
        $stmt->execute();
        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }

    function getClient($id) {
        $sql = "SELECT * FROM clients WHERE id = :id";
        $stmt = $this->connection->prepare($sql);
        $stmt->bindParam('id', $id);
        $stmt->execute();
        return $stmt->fetch(PDO::FETCH_ASSOC);
    }

    function updateClient($id, $client) {
        $sql = "UPDATE clients SET first_name = :first_name, last_name = :last_name, email = :email, company = :company, project = :project, phone = :phone WHERE id = :id";
        $stmt = $this->connection->prepare($sql);
        $stmt->bindParam('id', $id);
        $stmt->bindParam('first_name', $client['first_name']);
        $stmt->bindParam('last_name', $client['last_name']);
        $stmt->bindParam('email', $client['email']);
        $stmt->bindParam('company', $client['company']);
        $stmt->bindParam('project', $client['project']);
        $stmt->bindParam('phone', $client['phone']);
        $stmt->execute();
    }
    function destroyClient($id) {
        $sql = "DELETE FROM clients WHERE id = :id";
        $stmt = $this->connection->prepare($sql);
        $stmt->bindParam('id', $id);
        $stmt->execute();
    }
}
?>