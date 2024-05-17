const passport = require("passport");
const { Strategy, ExtractJwt } = require("passport-jwt");
const config = require("./config");

module.exports = (app) => {
  const Users = app.models.Users;
  const { jwt } = config;

  const params = {
    secretOrKey: jwt.secret,
    jwtFromRequest: ExtractJwt.fromHeader("Authorization"),
  };

  passport.use(
    new Strategy(params, async (payload, done) => {
      try {
        const { id } = payload;
        const attributes = ["id", "email"];
        const option = { attributes };
        const user = await Users.findByPk(id, option);
        done(null, user);
      } catch (err) {
        done(err, null);
      }
    }),
  );

  return {
    initialize: () => passport.initialize(),
    authenticate: () => passport.authenticate("jwt", jwt.option),
  };
};
