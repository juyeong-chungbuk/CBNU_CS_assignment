<?php
include_once 'dbconfig.php';

// Select a database
$dbname = "school";
mysqli_select_db($conn, $dbname) or die('DB selection failed');

// Create table
$sql =	"CREATE TABLE student(
	id INT(4) UNSIGNED AUTO_INCREMENT, 
	name VARCHAR(20) NOT NULL,
	age INT(3),
	email VARCHAR(50),
	phone VARCHAR(30),
	reg_date TIMESTAMP,
	PRIMARY KEY(id)
	)";

if($conn->query($sql) === TRUE){
	echo "Table student created successfully";
	echo "<br/><a href='insert.php'>Click to add data !</a>";
}else{
	echo "Error creating table: ";
	echo "<br/>";
	echo $conn->error;
}

$conn->close();
?>