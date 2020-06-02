#!/usr/bin/node
const request = require('request');
if (process.argv.length === 3) {
  const id = process.argv[2];
  const url = `https://swapi-api.hbtn.io/api/films/${id}`;

  request(url, function (err, response, body) {
    if (err) {
      console.log(err);
    } else {
      for (const ch of JSON.parse(body).characters) {
        request(ch, function (err, response, body) {
          if (err) {
            console.log(err);
          } else {
            console.log(JSON.parse(body).name);
          }
        });
      }
    }
  });
}
