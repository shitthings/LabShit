# Week1
## Basic HTML, CSS
```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>SNIST</title>
  <style>
    body { margin: 0; }
    .header, .column { padding: 20px; }
    .header { background: #f1f1f1; text-align: center; }
    .topnav { background: #333; overflow: hidden; }
    .topnav a { float: left; color: white; padding: 14px 16px; padding: 20px; text-decoration: none; }
    .topnav a:hover { background: #ddd; color: black; }
    .row { display: flex; }
    .column { flex: 1; }
  </style>
</head>
<body>
  <div class="header">
    <h1>SNIST</h1>
    <p>Sreenidhi Institute of Science and Technology</p>
  </div>
  <div class="topnav">
    <a href="#">Home</a>
    <a href="#">About</a>
    <a href="#">Departmental Info</a>
  </div>
  <div class="row">
    <div class="column">
      <h2>College Info</h2>
      <p>Sreenidhi Institute of Science and Technology, established in 1997.</p>
    </div>
    <div class="column">
      <h2>Branches Info</h2>
      <p>CSE, IT, ECE, EEE, MECH, CIVIL...</p>
    </div>
    <div class="column">
      <h2>Address</h2>
      <p>Ghatkesar, Hyderabad</p>
    </div>
  </div>
</body>
</html>
```
## Types of CSS
### inline
```html
<!DOCTYPE html>
<html>
<body>
<h1 style="color:blue;">A Blue Heading</h1>
<p style="color:red;">A red paragraph.</p>
</body>
</html>
```
### internal
```html
<!DOCTYPE html>
<html>
<head>
<style>
body {background-color: powderblue;}
h1 {color: blue;}
p {color: red;}
</style>
</head>
<body>
<h1>This is a heading</h1>
<p>This is a paragraph.</p>
</body>
</html>
```
### External
#### HTML
```html
<!DOCTYPE html>
<html>
<head>
 <link rel="stylesheet" href="ext.css">
</head>
<body>
<h1>This is a heading</h1>
<p>This is a paragraph.</p>
</body>
</html>
```
#### CSS
```css
body {
    background-color: powderblue;
   }
   h1 {
    color: blue;
   }
   p {
    color: red;
}
```
## Personal Info page
```html
<!DOCTYPE html>
<html>
<head>
  <title>Personal Info</title>
  <style>
    body, h1, p { margin: 0; padding: 0; }
    .section {
      height: 400px; display: flex; justify-content: center; align-items: center;
      color: black; margin: auto; max-width: 80%; 
    }
    .firstsection { background: green; }
    .secondsection { background: blue; }
    .text-big { font-size: 35px; font-weight: bold; }
    .text-small { font-size: 18px; }
  </style>
</head>
<body>
  <section class="section firstsection">
    <div>
      <h1 class="text-big">Personal Information</h1>
      <p class="text-small">Name: Xina <br> Roll No: 21311A6669 <br> SECTION: Nach</p>
    </div>
  </section>
  <section class="section secondsection">
    <div>
      <h1 class="text-big">Contact Details</h1>
      <p class="text-small">E-Mail: meow@beluga.ru <br> Mobile: 1234321234</p>
    </div>
  </section>
</body>
</html>
```
## Form
### HTML
```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Sign Up Form</title>
  <link rel="stylesheet" href="styles.css"> <!-- Link to your CSS file -->
</head>
<body>
  <form action="action_page.php" style="border:1px solid #ccc; padding: 16px;">
    <h1>Sign Up</h1>
    <p>Please fill in this form to create an account.</p>
    <hr>
    <label for="email"><b>Email</b></label>
    <input type="text" placeholder="Enter Email" name="email" required>
    
    <label for="psw"><b>Password</b></label>
    <input type="password" placeholder="Enter Password" name="psw" required>
    
    <label for="psw-repeat"><b>Repeat Password</b></label>
    <input type="password" placeholder="Repeat Password" name="psw-repeat" required>
    
    <label>
      <input type="checkbox" checked="checked" name="remember"> Remember me
    </label>
    <p>By creating an account you agree to our <a href="#" style="color:dodgerblue">Terms & Privacy</a>.</p>
    
    <div class="clearfix">
      <button type="button" class="cancelbtn">Cancel</button>
      <button type="submit" class="signupbtn">Sign Up</button>
    </div>
  </form>
</body>
</html>
```
### CSS
```css
* { box-sizing: border-box; }
input[type=text], input[type=password] {
  width: 100%;
  padding: 15px;
  margin: 5px 0 22px;
  border: none;
  background: #f1f1f1;
}
input:focus {
  background-color: #ddd;
  outline: none;
}
hr { border: 1px solid #f1f1f1; margin-bottom: 25px; }
button {
  width: 100%; padding: 14px 20px;
  background-color: #04AA6D; color: white;
  border: none; cursor: pointer;
  margin: 8px 0; opacity: 0.9;
}
button:hover { opacity: 1; }
.cancelbtn { background-color: #f44336; }
.cancelbtn, .signupbtn {
  width: 50%; float: left;
}
.clearfix::after { content: ""; clear: both; display: table; }
@media (max-width: 300px) {
  .cancelbtn, .signupbtn { width: 100%; }
}
```
# Week2
## Types of JS insertion
### Scripts in the Head and Body
```html
<!DOCTYPE html>
<head>
  <meta charset="utf-8" />
  <title> Script in head and body section </title>
  <script type="text/javascript">
    JavaScript statements.......
  </script>
</head>
<body>
  <script type="text/javascript">
    JavaScript statements.......
  </script>
</body>undefined</html> 
```
### Two Scripts in the Body undefined
```html
<!DOCTYPE html>undefined<head>
  <meta charset="utf-8" />
  <title> Two Scripts in the Body </title>undefined
</head>undefined<body>
  <script type="text/javascript" scr="jsexample.js"></script>
  <script type="text/javascript">
    JavaScript statements.......
  </script>undefined
</body>undefined</html>
```
## Rollover menus
### HTML
```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Dropdown Menu</title>
  <link rel="stylesheet" href="styles.css"> <!-- Link to your CSS file -->
</head>
<body>
  <div class="dropdown">
    <button onclick="toggleDropdown()" class="dropbtn">Dropdown</button>
    <div id="myDropdown" class="dropdown-content">
      <a href="#">Link 1</a>
      <a href="#">Link 2</a>
      <a href="#">Link 3</a>
    </div>
  </div>
  <script src="scripts.js"></script> <!-- Link to your JavaScript file -->
</body>
</html>
```
### CSS
```css
.dropbtn {
  background-color: #3498DB;
  color: white;
  padding: 16px;
  font-size: 16px;
  border: none;
  cursor: pointer;
}

.dropbtn:hover, .dropbtn:focus {
  background-color: #2980B9;
}

.dropdown {
  position: relative;
  display: inline-block;
}

.dropdown-content {
  display: none;
  position: absolute;
  background-color: #f1f1f1;
  min-width: 160px;
  box-shadow: 0 8px 16px rgba(0, 0, 0, 0.2);
  z-index: 1;
}

.dropdown-content a {
  color: black;
  padding: 12px 16px;
  text-decoration: none;
  display: block;
}

.dropdown-content a:hover {
  background-color: #ddd;
}

.show {
  display: block;
}
```
### JS
```js
function toggleDropdown() {
  document.getElementById("myDropdown").classList.toggle("show");
}

window.onclick = function(event) {
  if (!event.target.matches('.dropbtn')) {
    var dropdowns = document.getElementsByClassName("dropdown-content");
    for (var i = 0; i < dropdowns.length; i++) {
      var openDropdown = dropdowns[i];
      if (openDropdown.classList.contains('show')) {
        openDropdown.classList.remove('show');
      }
    }
  }
}
```
## Calc
```js
function calculate(operator, number1, number2) {
  switch (operator) {
    case '+':
      return number1 + number2;
    case '-':
      return number1 - number2;
    case '*':
      return number1 * number2;
    case '/':
      return number2 !== 0 ? number1 / number2 : "Division by zero error";
    default:
      return "Invalid operator";
  }
}
const operator = prompt('Enter operator ( +, -, *, / ): ');
const number1 = parseFloat(prompt('Enter first number: '));
const number2 = parseFloat(prompt('Enter second number: '));
const result = calculate(operator, number1, number2);
console.log(`${number1} ${operator} ${number2} = ${result}`);
```
# Week3
## Book information
```xml
<bookstore>
	<book>
		<title>web programming</title>
		<author>chrisbates</author>
		<ISBN>123-456-789</ISBN>
		<publisher>wiley</publisher>
		<edition>3</edition>
		<price>350</price>
	</book>
	<book>
		<title>internet worldwideweb</title>
		<author>ditel&amp;ditel</author>
		<ISBN>123-456-781</ISBN>
		<publisher>person</publisher>
		<edition>3</edition>
		<price>450</price>
	</book>
</bookstore>
```
## DTD
### Bookstore.xml
```xml
<!DOCTYPE bookstore SYSTEM "C:\wt\bookstore.dtd">
<bookstore>
	<book>
		<title>web programming</title>
		<author>chrisbates</author>
		<ISBN>123-456-789</ISBN>
		<publisher>wiley</publisher>
		<edition>3</edition>
		<price>350</price>
	</book>
	<book>
		<title>internet worldwideweb</title>
		<author>ditel&amp;ditel</author>
		<ISBN>123-456-781</ISBN>
		<publisher>person</publisher>
		<edition>3</edition>
		<price>450</price>
	</book>
</bookstore>
```
### bookstore.dtd usting dtd
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!ELEMENT bookstore (book+)>
<!ELEMENT book (title,author,ISBN,publisher,edition,price)>
<!ELEMENT title (#PCDATA)>
<!ELEMENT author (#PCDATA)>
<!ELEMENT ISBN (#PCDATA)>
<!ELEMENT publisher (#PCDATA)>
<!ELEMENT edition (#PCDATA)>
<!ELEMENT price (#PCDATA)>
```
### using bookstore.xsd
```xml
<?xml version="1.0" encoding="UTF-8"?>
<xs:schema elementFormDefault="qualified" attributeFormDefault="unqualified"
	xmlns:xs="http://www.w3.org/2001/XMLSchema">
	<xs:element name="bookstore">
		<xs:complexType>
			<xs:sequence>
				<xs:element name="book" maxOccurs="unbounded">
					<xs:complexType>
						<xs:sequence>
							<xs:element name="title" type="xs:string"></xs:element>
							<xs:element name="author" type="xs:string"></xs:element>
							<xs:element name="ISBN" type="xs:string"></xs:element>
							<xs:element name="publisher" type="xs:string"></xs:element>
							<xs:element name="edition" type="xs:int"></xs:element>
							<xs:element name="price" type="xs:decimal"></xs:element>
						</xs:sequence>
					</xs:complexType>
/xs:element>
				</xs:sequence>
			</xs:complexType>
		</xs:element>
	</xs:schema>
```
# Week4
## Student info
### JSON
```json
[
  {
    "name": "arun",
    "gender": "Male",
    "physics": 88,
    "maths": 87,
    "english": 78
  },
  {
    "name": "rajesh",
    "gender": "Male",
    "physics": 96,
    "maths": 100,
    "english": 95
  },
  {
    "name": "moorthy",
    "gender": "Male",
    "physics": 89,
    "maths": 90,
    "english": 70
  },
  {
    "name": "raja",
    "gender": "Male",
    "physics": 30,
    "maths": 25,
    "english": 40
  },
  {
    "name": "usha",
    "gender": "Female",
    "physics": 67,
    "maths": 45,
    "english": 78
  },
  {
    "name": "priya",
    "gender": "Female",
    "physics": 56,
    "maths": 46,
    "english": 78
  },
  {
    "name": "Sundar",
    "gender": "Male",
    "physics": 12,
    "maths": 67,
    "english": 67
  },
  {
    "name": "Kavitha",
    "gender": "Female",
    "physics": 78,
    "maths": 71,
    "english": 67
  },
  {
    "name": "Dinesh",
    "gender": "Male",
    "physics": 56,
    "maths": 45,
    "english": 67
  },
  {
    "name": "Hema",
    "gender": "Female",
    "physics": 71,
    "maths": 90,
    "english": 23
  },
  {
    "name": "Gowri",
    "gender": "Female",
    "physics": 100,
    "maths": 100,
    "english": 100
  },
  {
    "name": "Ram",
    "gender": "Male",
    "physics": 78,
    "maths": 55,
    "english": 47
  },
  {
    "name": "Murugan",
    "gender": "Male",
    "physics": 34,
    "maths": 89,
    "english": 78
  },
  {
    "name": "Jenifer",
    "gender": "Female",
    "physics": 67,
    "maths": 88,
    "english": 90
  }
]
```
### Whole thing in html file
```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Student Data Table</title>
  <style>
    table {
      width: 100%;
      border-collapse: collapse;
    }
    table, th, td {
      border: 1px solid black;
    }
    th, td {
      padding: 8px;
      text-align: left;
    }
    th {
      background-color: #f2f2f2;
    }
  </style>
</head>
<body>
  <h1>Student Data</h1>
  <div id="table-container"></div>

  <script>
    // JSON data
    const jsonData = [
      { "name": "arun", "gender": "Male", "physics": 88, "maths": 87, "english": 78 },
      { "name": "rajesh", "gender": "Male", "physics": 96, "maths": 100, "english": 95 },
      { "name": "moorthy", "gender": "Male", "physics": 89, "maths": 90, "english": 70 },
      { "name": "raja", "gender": "Male", "physics": 30, "maths": 25, "english": 40 },
      { "name": "usha", "gender": "Female", "physics": 67, "maths": 45, "english": 78 },
      { "name": "priya", "gender": "Female", "physics": 56, "maths": 46, "english": 78 },
      { "name": "Sundar", "gender": "Male", "physics": 12, "maths": 67, "english": 67 },
      { "name": "Kavitha", "gender": "Female", "physics": 78, "maths": 71, "english": 67 },
      { "name": "Dinesh", "gender": "Male", "physics": 56, "maths": 45, "english": 67 },
      { "name": "Hema", "gender": "Female", "physics": 71, "maths": 90, "english": 23 },
      { "name": "Gowri", "gender": "Female", "physics": 100, "maths": 100, "english": 100 },
      { "name": "Ram", "gender": "Male", "physics": 78, "maths": 55, "english": 47 },
      { "name": "Murugan", "gender": "Male", "physics": 34, "maths": 89, "english": 78 },
      { "name": "Jenifer", "gender": "Female", "physics": 67, "maths": 88, "english": 90 }
    ];

    function createTable(data) {
      let table = "<table>";
      table += `<tr>
        <th>Name</th>
        <th>Physics</th>
        <th>Maths</th>
        <th>English</th>
      </tr>`;

      data.forEach(student => {
        table += "<tr>";
        table += `<td>${student.name}</td>`;
        table += `<td>${student.physics}</td>`;
        table += `<td>${student.maths}</td>`;
        table += `<td>${student.english}</td>`;
        table += "</tr>";
      });

      table += "</table>";
      document.getElementById("table-container").innerHTML = table;
    }

    createTable(jsonData);
  </script>
</body>
</html>
```
# Week5
## DataBase Table Creation
```php
<?php
$servername = "localhost"'
$username = "root";
$password = "";
$database = "dbsam";
$conn = mysqli_connect($servername,$username,$password,$database);
echo "connection was successfull";
$sql = "create table 'table name' ('sno' int (5), 'name' varchar(12), primary key ('sno'))";
?>
```
## DataBase Creation
```php
<?php
$servername = "localhost"'
$username = "root";
$password = "";
$conn = mysqli_connect($servername,$username,$password);
$sql = "CREATE DATABASE dbsam";
mysqli_query($conn,$sql);
echo "connection was successfull";
?>
```
## DataBase Connection
```php
<?php
echo "welcome to connect to db";
$servername = "localhost"'
$username = "root";
$password = "";
$conn = mysqli_connect($servername,$username,$password);
echo "connection was successfull";
?>
```
# Week6
## PHP to insert values form HTML to database
### HTML page
```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Add Records</title>
</head>
<body>
  <form action="insert.php" method="post">
    <p>
      <label for="firstName">First Name:</label>
      <input type="text" name="first_name" id="firstName" required>
    </p>
    <p>
      <label for="phone">Phone Number:</label>
      <input type="text" name="phone" id="phone" required>
    </p>
    <p>
      <label for="email">Email Address:</label>
      <input type="email" name="email" id="email" required>
    </p>
    <p>
      <label for="gender">Gender:</label>
      <input type="text" name="gender" id="gender" required>
    </p>
    <p>
      <label for="address">Address:</label>
      <input type="text" name="address" id="address" required>
    </p>
    <p>
      <label for="dob">DOB:</label>
      <input type="date" name="dob" id="dob" required>
    </p>
    <p>
      <label for="language">Language Known:</label>
      <input type="text" name="language" id="language" required>
    </p>
    <input type="submit" value="Add Records">
  </form>
</body>
</html>
```
### PHP
```php
<?php
// Database connection
$server = "localhost";
$username = "username";
$password = "password";
$database = "demo";

// Create connection
$conn = mysqli_connect($server, $username, $password, $database);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Sanitize input data
$firstName = mysqli_real_escape_string($conn, $_POST['first_name']);
$phone = mysqli_real_escape_string($conn, $_POST['phone']);
$email = mysqli_real_escape_string($conn, $_POST['email']);
$gender = mysqli_real_escape_string($conn, $_POST['gender']);
$address = mysqli_real_escape_string($conn, $_POST['address']);
$dob = mysqli_real_escape_string($conn, $_POST['dob']);
$language = mysqli_real_escape_string($conn, $_POST['language']);

// Prepare and execute SQL query
$sql = "INSERT INTO registration (first_name, phone, email, gender, address, dob, language)
        VALUES ('$firstName', '$phone', '$email', '$gender', '$address', '$dob', '$language')";

if (mysqli_query($conn, $sql)) {
    echo "Records added successfully.";
} else {
    echo "Error: " . mysqli_error($conn);
}

// Close connection
mysqli_close($conn);
?>
```
## PHP to select values form database table.
```php
<?php
// Database connection
$server = "localhost";
$username = "username";
$password = "password";
$database = "demo";

// Create connection
$conn = mysqli_connect($server, $username, $password, $database);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// SQL query to select all records
$sql = "SELECT * FROM registration";
$result = mysqli_query($conn, $sql);

// Check if query was successful
if ($result) {
    // Check if there are any records
    if (mysqli_num_rows($result) > 0) {
        // Start the table
        echo "<table border='1'>";
        echo "<tr>";
        echo "<th>ID</th>";
        echo "<th>First Name</th>";
        echo "<th>Phone Number</th>";
        echo "<th>Email</th>";
        echo "<th>Gender</th>";
        echo "<th>Address</th>";
        echo "<th>DOB</th>";
        echo "<th>Language</th>";
        echo "</tr>";
        
        // Fetch and display records
        while ($row = mysqli_fetch_assoc($result)) {
            echo "<tr>";
            echo "<td>{$row['id']}</td>";
            echo "<td>{$row['first_name']}</td>";
            echo "<td>{$row['phone_no']}</td>";
            echo "<td>{$row['email']}</td>";
            echo "<td>{$row['gender']}</td>";
            echo "<td>{$row['address']}</td>";
            echo "<td>{$row['dob']}</td>";
            echo "<td>{$row['lang']}</td>";
            echo "</tr>";
        }
        
        // End the table
        echo "</table>";
        
        // Free result set
        mysqli_free_result($result);
    } else {
        echo "No records found.";
    }
} else {
    echo "Error: " . mysqli_error($conn);
}

// Close connection
mysqli_close($conn);
?>
```
## PHP to update existing records of a database table
```php
<?php
// Database connection details
$server = "localhost";
$username = "username";
$password = "password";
$database = "demo";

// Create connection
$conn = mysqli_connect($server, $username, $password, $database);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// SQL query to update the record
$sql = "UPDATE registration SET email='xyz@abcdmail.com' WHERE id=1";

// Execute the query
if (mysqli_query($conn, $sql)) {
    echo "Record updated successfully.";
} else {
    echo "Error: " . mysqli_error($conn);
}

// Close connection
mysqli_close($conn);
?>
```
## PHP to validate user login
```php
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login Page</title>
</head>
<body>
    <form method="post" action="login.php">
        <label for="username">Username:</label>
        <input type="text" id="username" name="username" placeholder="Enter username" required><br>
        
        <label for="password">Password:</label>
        <input type="password" id="password" name="password" placeholder="Enter password" required><br>
        
        <input type="submit" name="submit" value="Login">
        <input type="reset" value="Reset">
    </form>
</body>
</html>
<?php
// Database connection details
$server = "localhost";
$username = "username";
$password = "password";
$database = "database";

// Create connection
$con = mysqli_connect($server, $username, $password, $database);

// Check connection
if (!$con) {
    die("Connection failed: " . mysqli_connect_error());
}

// Check if form is submitted
if (isset($_POST['submit'])) {
    // Get input values and escape them to prevent SQL injection
    $name = mysqli_real_escape_string($con, $_POST['username']);
    $password = mysqli_real_escape_string($con, $_POST['password']);
    
    // Prepare SQL query
    $sql = "SELECT name FROM table_name WHERE name='$name' AND password='$password'";
    
    // Execute SQL query
    $result = mysqli_query($con, $sql);
    
    // Check if login is successful
    if (mysqli_num_rows($result) > 0) {
        header("Location: home.php");
        exit(); // Ensure no further code is executed
    } else {
        echo "Login denied. Please check your username and password.";
    }
}

// Close connection
mysqli_close($con);
?>
```
# Week7
## Create angular project with name MY_First_Angular_App and write simple Angular program to display the name SNIST.
### Steps
```md
Installation of Angular:
1. Download and Install Node.js and NPM from Node.js website
2. Verify Node installation with the following commands:
node -v
npm -v
3. Install Angular CLI globally using the following command:
 npm install -g @angular/cli
4. Verify Angular installation using the following:
ng version
Creation of Angular project:
1. Create a new Angular project with the following command:
ng new my-first-angular-app
2. Navigate to the project directory:
 cd my-first-angular-app
3. In the “app.component.html” file, add the following code:
4. Run the Angular development server:
ng serve
5. Navigate to “localhost:4200” to view the output
```
### app.component.html
```html
<!DOCTYPE html>
<html>
  <head>
    <title>AngularJS First App</title>
    <script src="scripts/angular.js"></script>
  </head>
  <body>
    <div ng-app="myApp">
      <h1>SNIST angular application</h1>
    </div>
  </body>
</html>
```
# Week 8
## Create servlet program to display ‘HELLO WORLD’ message using tomcat server.
### Steps
```md
Steps to execute servlet program:
1. Open XAMPP Control Panel and start the Apache Tomcat service
2. In the XAMPP Tomcat directory, navigate to the “Webapps” folder
3. Create a new folder to host the servlet application “helloworld”
4. In the new folder, create a “WEB-INF” folder
5. In the “WEB-INF” folder, create a file “web.xml” with the following contents:
6. Create a new folder called “classes” within the “WEB-INF” folder
7. In the classes folder, create a file “Test.java” with the following contents:
8. Save the file and compile it using the following command:
`javac -classpath “C:\xampp\tomcat\lib\servlet-api.jar” Test.java`
9. Open the browser and navigate to the url “localhost:8080/helloworld/demo” to view the
output.
```
### Web.xml
```xml
<web-app>
    <servlet>
        <servlet-name>XYZ</servlet-name>
        <servlet-class>Test</servlet-class>
    </servlet>
    
    <servlet-mapping>
        <servlet-name>XYZ</servlet-name>
        <url-pattern>/demo</url-pattern>
    </servlet-mapping>
</web-app>
```
### Test.java
```java
import javax.servlet.*;
import java.io.*;

public class Test extends GenericServlet {

    @Override
    public void service(ServletRequest req, ServletResponse res) throws IOException, ServletException {
        PrintWriter o = res.getWriter();
        o.print("Hello World");
    }
}
```
# Extras
## jsondata.txt
```html
<!DOCTYPE html>
<html>
<head>
<style>
table{
border-collapse: collapse;
}
th,td{
border: 1px solid black;
padding: 8px;
text-align: center;
}
th{
background-color: black;
color: white;
}
</style>
</head>
<body>
<center>
<h1> How to populate Json data into table</h1>
<h2> Json- Javascript</h2>
<hr/>
<table id="mytable">
<thead>
<tr>
<th>name</th>
<th>email</th>
<th>age</th>
</tr>
</thead>
<tbody></tbody>
</center>
</body>
<script>
const jsonData=[
{
"name":  "charan",
"email":"charan@gmail.com",
"age":30
},
{
"name":  "Roy",
"email":"roy@gmail.com",
"age":35
},
{
"name":  "sam",
"email":"sam@gmail.com",
"age":40
}
];
const tableBody=document.querySelector("#mytable tbody");
jsonData.forEach(person =>{
const row=document.createElement('tr');

const nameCell=document.createElement('td');
nameCell.textContent=person.name;
row.appendChild(nameCell);

const emailCell=document.createElement('td');
emailCell.textContent=person.email;
row.appendChild(emailCell);

const ageCell=document.createElement('td');
ageCell.textContent=person.age;
row.appendChild(ageCell);
tableBody.appendChild(row);

});

</script>
</html>
```
## Calc.txt
```html
<!DOCTYPE html>
<html>
<head>
<body>
<input type="number" name="first" id="first" step="any"/>
<select id="ope">
<option value="+">+</option>
<option value="-">-</option>
<option value="*">*</option>
<option value="/">/</option>
</select>
<input type="number" name="second" id="second" step="any"/>
<br/>
<br/>
<button onclick="cal()"> calculate</button>
<input type="text" name="" id="res" readonly="" />
</body>
<script type="text/javascript">
function cal(){
var opr1 = document.getElementById('first').value;
var opr2 = document.getElementById('second').value;
var ope = document.getElementById('ope').value;
if (ope == '+') {
var res = parseInt(opr1) + parseInt(opr2);
}
if (ope == '-') {
var res = parseInt(opr1) - parseInt(opr2);
}
if (ope == '*') {
var res = parseInt(opr1) * parseInt(opr2);
}
if (ope == '/') {
var res = parseInt(opr1) / parseInt(opr2);
}
document.getElementById('res').value = res;
}
</script>
</html>
```