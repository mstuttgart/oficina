module.exports = (app) => {
  const Users = app.models.users;

  app.get("/users/:id", async (req, res) => {
    try {
      const { id } = req.params;
      const attributes = ["id", "name", "email"];
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
  });

  app.delete("/users/:id", async (req, res) => {
    try {
      const { id } = req.params;
      const where = { id };
      await Users.destroy({ where });
      res.sendStatus(204);
    } catch (err) {
      res.status(412).json({ msg: err.message });
    }
  });

  app.post("/users", async (req, res) => {
    try {
      const result = await Users.create(req.body);
      res.json(result);
    } catch (err) {
      res.status(412).json({ msg: err.message });
    }
  });
};
