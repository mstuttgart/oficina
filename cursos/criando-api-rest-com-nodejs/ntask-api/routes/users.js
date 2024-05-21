module.exports = (app) => {
  const Users = app.models.users;

  app
    .route("/user")
    .all(app.auth.authenticate())
    .get(async (req, res) => {
      try {
        const { id } = req.user;
        const attributes = ['id', 'name', 'email'];
        const options = { attributes };
        const result = await Users.findByPk(id, options);
        if (result) {
          res.json(result);
        } else {
          res.sendStatus(404);
        }
      } catch (err) {
        res.status(412).json({ msg: err.message });
      }
    })
    .delete(async (req, res) => {
      try {
        const { id } = req.user;
        const where = { id };
        await Users.destroy({ where });
        res.sendStatus(204);
      } catch (err) {
        res.status(412).json({ msg: err.message });
      }
    });

  // Essa rota não precisa de autenticação
  // Pois é uma rota de cadastro de usuário
  app.post("/users", async (req, res) => {
    try {
      const result = await Users.create(req.body);
      res.json(result);
    } catch (err) {
      res.status(412).json({ msg: err.message });
    }
  });
};
