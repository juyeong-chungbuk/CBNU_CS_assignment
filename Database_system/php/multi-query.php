<?php
include_once 'dbconfig.php';

// Select a database
$dbname = "school";
mysqli_select_db($conn, $dbname) or die('DB selection failed');

$sql = "INSERT INTO student(name, age, email, phone) 
		VALUES('KDY', 24, 'kdy@chungbuk.ac.kr', '010-1111-2222');";
$sql .= "INSERT INTO student(name, age, email, phone) 
		VALUES('WJHM', 31, 'wjhm@chungbuk.ac.kr', '010-3333-4444');";
$sql .= "INSERT INTO student(name, age, email, phone) 
		VALUES('SRB', 22, 'srb@chungbuk.ac.kr', '010-5555-6666')";

if($conn->multi_query($sql) === TRUE){
	echo "New records created successfully";
	echo "<br/><a href='prepare.php'>Click to use prepared query !</a>";
}else{
	echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>