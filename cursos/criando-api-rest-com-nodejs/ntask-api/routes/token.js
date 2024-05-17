const bcrypt = require("bcrypt");
const jwt = require("jwt-simple");
const config = require("../config.js");

module.exports = (app) => {
  const Users = app.models.users;
  const { secret } = config.jwt;

  app.post("/token", async (req, res) => {
    try {
      const { email, password } = req.body;

      if (email && password) {
        const where = { email };
        const user = await Users.findOne({ where });

        if (bcrypt.compateSync(password, user.password)) {
          const payload = { id: user.id };
          const token = jwt.encode(payload, secret);
          return res.json({ token });
        }
      }

      return res.sendStatus(401);
    } catch (err) {
      return res.sendStatus(401);
    }
  });
};
