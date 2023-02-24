//
// This is only a SKELETON file for the 'Tournament' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const tournamentTally = (matchsData) => {

  const header = 'Team                           | MP |  W |  D |  L |  P'

  if (!matchsData)
    return header

  const teamData = {}

  for (let line of matchsData.split('\n')) {

    const lineData = line.split(';')

    let team1 = lineData[0]
    let team2 = lineData[1]
    let result = lineData[2]

    // Caso team1 nao esteja na tabela, criamos
    // seu cadastro e inicialiazamos os valores
    if (!teamData.hasOwnProperty(team1)) {
      teamData[team1] = {
        name: team1,
        match: 0,
        win: 0,
        draw: 0,
        loss: 0,
        points: 0,
      }
    }

    // Caso team2 nao esteja na tabela, criamos
    // seu cadastro e inicialiazamos os valores
    if (!teamData.hasOwnProperty(team2)) {
      teamData[team2] = {
        name: team2,
        match: 0,
        win: 0,
        draw: 0,
        loss: 0,
        points: 0,
      }      
    
    }

    teamData[team1].match += 1
    teamData[team2].match += 1

    if (result === 'win'){
      teamData[team1].win += 1
      teamData[team1].points += 3
    
      teamData[team2].loss += 1

    } else if (result === 'draw') {
      teamData[team1].draw += 1
      teamData[team1].points += 1
      
      teamData[team2].draw += 1
      teamData[team2].points += 1
      
    } else if (result === 'loss') {
      teamData[team1].loss += 1
      
      teamData[team2].win += 1
      teamData[team2].points += 3
    }
  }

  let tournamentData = []

  for (let team in teamData){
    tournamentData.push(teamData[team])
  }

  // ordenacao por pontos (maior para menos)
  tournamentData.sort(function (a, b) { 
    return b.points - a.points
  })

  // ordenacao por nome em casos de empate
  tournamentData.sort(function (a, b) {

    if (a.points === b.points)
      return a.name.localeCompare(b.name)
    else
      return 0
    
  })

  const table = []
    
  for (let data of tournamentData){
    
    table.push(`${data.name.padEnd('31')}|  ${data.match} |  ${data.win} |  ${data.draw} |  ${data.loss} |${data.points.toString().padStart('3')}`
               
    )  
  }
  
  table.unshift(header)
    
  return table.join('\n')
  
};
