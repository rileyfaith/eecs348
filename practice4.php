<html>
    <head>
        <h1>Multiplication Table Generator</h1>
        <style>
            table, th, td {
                border: 1px solid black;
                border-collapse: collapse;
                padding: 5px;
                text-align: center;
            }
        </style>
    </head>
    <body>
        <h2>Enter a Number: </h2>
        <form action="" method="post">
            <input type="number" name="number" required>
            <button type="onclick">Generate Table!</button>
        </form>
    </body>
</html>

<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST" && !empty($_POST["number"])) {
        $number = intval($_POST["number"]);

        echo "<h3>Multiplication Table for: $number</h3>";
        echo "<table>";
        echo "<tr><th>x</th>";
        for ($col = 1; $col <= $number; $col++) {
            echo "<th>$col</th>";
        }
        echo "</tr>";

        for ($row = 1; $row <= $number; $row++) {
            echo "<tr>";
            echo "<th>$row</th>";
            for ($col = 1; $col <= $number; $col++) {
                echo "<td>" . ($row * $col) . "</td>";
            }
            echo "</tr>";
        }
        echo "</table>";
    }
?>