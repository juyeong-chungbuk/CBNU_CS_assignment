<?php
include_once 'dbconfig.php';

// Create database
$sql = "CREATE DATABASE school";

if($conn->query($sql) === TRUE){
	echo "Database school created successfully";
	echo "<br/><a href='create_table.php'>Click to create a table !</a>";
}else{
	echo "Error creating database: ";
	echo "<br/>";
	echo $conn->error;
}

$conn->close();
?>

