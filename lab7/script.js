function changeStyle() {
    var paragraph = document.getElementById('paragraph');
    var backgroundRGBinput = document.getElementById('background_rgbinput').value;
    var borderRGBinput = document.getElementById('border_rgbinput').value;
    var borderWidth = document.getElementById('borderpxinput').value;

    paragraph.style.backgroundColor = 'rgb(' + backgroundRGBinput +')';
    paragraph.style.borderColor = 'rgb(' + borderRGBinput +')';
    paragraph.style.borderWidth = borderWidth + 'px';
    paragraph.style.borderStyle = 'solid';
}