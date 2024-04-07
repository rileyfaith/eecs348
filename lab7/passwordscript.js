function verifyPasswords() {
    var password1 = document.getElementById('password1').value;
    var password2 = document.getElementById('password2').value;

    if (password1.length < 8 || password2.length < 8) {
        alert("Password must be at least 8 characters in length.");
        return false;
    }

    if (password1 != password2) {
        alert("Passwords do not match.");
        return false;
    }

    alert("Passwords match and are valid!")
    return true;
}
