var fruit = [
    {
        "id": 1,
        "name": "Apple",
        "src": "./img/Apple.jpg",
        "price": "5"
    }, {
        "id": 2,
        "name": "Banana",
        "src": "./img/Banana.jpg",
        "price": "6"
    }, {
        "id": 3,
        "name": "Orange",
        "src": "./img/Orange.jpg",
        "price": "4"
    }, {
        "id": 4,
        "name": "Watermelon",
        "src": "./img/Watermelon.jpg",
        "price": "10"
    }, {
        "id": 5,
        "name": "Kiwi",
        "src": "./img/Kiwi.jpg",
        "price": "5"
    }, {
        "id": 6,
        "name": "Strawbery",
        "src": "./img/Strawbery.jpg",
        "price": "7"
    }, {
        "id": 7,
        "name": "Mangosteen",
        "src": "./img/Mangosteen.jpg",
        "price": "10"
    }, {
        "id": 8,
        "name": "Rich",
        "src": "./img/Rich.jpg",
        "price": "1"
    }, {
        "id": 9,
        "name": "Blueberry",
        "src": "./img/Blueberry.jpg",
        "price": "3"
    }, {
        "id": 10,
        "name": "Plum",
        "src": "./img/Plum.jpg",
        "price": "4"
    }, {
        "id": 11,
        "name": "Peach",
        "src": "./img/Peach.jpg",
        "price": "5"
    }, {
        "id": 12,
        "name": "Avocado",
        "src": "./img/Avocado.jpg",
        "price": "6"
    }, {
        "id": 13,
        "name": "Pineapple",
        "src": "./img/Pineapple.jpg",
        "price": "7"
    }, {
        "id": 14,
        "name": "Cherry",
        "src": "./img/Cherry.jpg",
        "price": "8"
    }, {
        "id": 15,
        "name": "Melon",
        "src": "./img/Melon.jpg",
        "price": "9"
    }, {
        "id": 16,
        "name": "Mango",
        "src": "./img/Mango.jpg",
        "price": "10"
    }
];

function table() {
    var i,
        j = 0;
    var k = 1;
    document.write(
        "<table><tr><td style='border: 0px; text-align: left;'><label>BEST FRUIT</label" +
        "></td></tr><tr>"
    );
    for (i = 0; i < fruit.length / 4; i++) {
        for (; k <= 4 * i + 4; k++) {
            document.write("<td id='index'>" + k + "</td>");
        }
        document.write("</tr>");

        document.write("<tr>");
        for (j = 4 * i; j < 4 * i + 4; j++) {
            document.write(
                '<td onclick="Change(' + j + ')"><img class="img" id="' + j + '" src="' +
                fruit[j].src + '"><p id="name' + j + '">' + fruit[j].name + '<br>' + fruit[j].price +
                ' $</td>'
            );
        }
        document.write("</tr>");
    }
    document.write("</table>");
}

var sum = 0;
var total_fruit = [];

function Change(id) {
    var property = document.getElementById("name" + id);
    if (document.getElementById(id).getAttribute('src') === fruit[id].src) {
        document
            .getElementById(id)
            .src = "./img/selected.jpg";
        property.style.backgroundColor = "rgba(245, 65, 41, 0.919)";
        sum += Number(fruit[id].price);
        total_fruit.splice(id, 0, fruit[id].name);
    } else {
        document
            .getElementById(id)
            .src = fruit[id]
            .src;
        property.style.backgroundColor = "white";
        sum -= Number(fruit[id].price);
        total_fruit.splice(total_fruit.indexOf(fruit[id].name), 1);
    }
}

function buy() {
    var i;
    if (sum === 0) {
        alert('Please select item!');
    } else {
        alert(total_fruit.join(' ') + ' selected!\nTotal : ' + sum + ' $');
    }
}
