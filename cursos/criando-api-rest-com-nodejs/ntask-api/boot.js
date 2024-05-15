module.exports = (app) => {
  async function start(port) {
    try {
      await app.db.authenticate();
      await app.db.sync();
      app.listen(port, () => {
        console.log(`NTask API - porta ${app.get("port")}`);
      });
    } catch (err) {
      console.log("Erro de conexão com o banco de dados.");
      console.log(err);
    }
  }
  start(app.get("port"));
};
