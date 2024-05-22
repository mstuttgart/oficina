const https = require("https");
const fs = require("fs");

const certs = {
  key: fs.readFileSync("ntask.key", "utf8"),
  cert: fs.readFileSync("ntask.cert", "utf8"),
};

module.exports = (app) => {
  async function start(port) {
    try {
      await app.db.authenticate();
      await app.db.sync();
      if (process.env.NODE_ENV !== "test") {
        const server = https.createServer(certs, app);
        server.listen(port, () => {
          console.log(`NTask API - porta ${app.get("port")}`);
        });
      }
    } catch (err) {
      console.log("Erro de conexão com o banco de dados.");
      console.log(err);
    }
  }
  start(app.get("port"));
};
