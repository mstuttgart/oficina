// @ts-check

/**
 * Given a certain command, help the chatbot recognize whether the command is valid or not.
 *
 * @param {string} command
 * @returns {boolean} whether or not is the command valid
 */

export function isValidCommand(command) {
  const rgx = /^chatbot/i;
  return rgx.test(command);
}

/**
 * Given a certain message, help the chatbot get rid of all the emoji's encryption through the message.
 *
 * @param {string} message
 * @returns {string} The message without the emojis encryption
 */
export function removeEmoji(message) {
  const rgx = new RegExp('emoji[0-9]+', 'gm');
  return message.replace(rgx, '');
}


/**
 * Given a certain phone number, help the chatbot recognize whether it is in the correct format.
 *
 * @param {string} number
 * @returns {string} the Chatbot response to the phone Validation
 */
export function checkPhoneNumber(number) {
  
  const rgx = /\(\+[0-9]{2}\) [0-9]{3}-[0-9]{3}-[0-9]{3}/;

  if (rgx.test(number))
    return "Thanks! You can now download me to your phone.";
  else
    return `Oops, it seems like I can\'t reach out to ${number}`

}

/**
 * Given a certain response from the user, help the chatbot get only the URL.
 *
 * @param {string} userInput
 * @returns {string[] | null} all the possible URL's that the user may have answered
 */
export function getURL(userInput) {

  const rgx = /[\w.]+\.(com|so)\b/gim;

  return userInput.match(rgx);
}

/**
 * Greet the user using the full name data from the profile.
 *
 * @param {string} fullName
 * @returns {string} Greeting from the chatbot
 */
export function niceToMeetYou(fullName) {
  const rgx = /[\w]+,\s[\w]+/gi;

  const result = fullName.replace(rgx, (text) => {

    let arr_split = text.split(/,\s/);
    arr_split.reverse();
    return arr_split.join(' ');

  });
  
  return `Nice to meet you, ${result}`;
}
