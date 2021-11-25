<?php
include_once 'dbconfig.php';

// Select a database
$dbname = "school";
mysqli_select_db($conn, $dbname) or die('DB selection failed');

// Insert a record
$sql =	"INSERT INTO student(name, age, email, phone) 
		VALUES('SJY', 22, 'sjy@chungbuk.ac.kr', '010-6546-5669')";

if($conn->query($sql) === TRUE){
	echo "New record created successfully";
	echo "<br/><a href='multi-query.php'>Click to add three data !</a>";
}else{
	echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>

