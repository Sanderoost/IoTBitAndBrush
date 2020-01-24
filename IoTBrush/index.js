// Database packages
const express = require("express");


// Database variables
const app = express()
    port = 2000;

const homepage = require('./controller/homepage.js');

app
    .use("/static", express.static("static"))
    .set("view engine", "pug")
    .get("/", homepage);


app.listen(port);