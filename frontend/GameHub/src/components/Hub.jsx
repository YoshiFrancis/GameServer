import React, { useEffect, useState } from 'react';
import hub from '../utils/hub'

const Hub = () => {
  const [lobbies, setLobbies] = useState([])
  useEffect(() => {
    setLobbies(hub.getLobbies());
  }, [])

  return (
  <div>
    <h1>Hello Hub</h1>
  </div>
  )
}

export default Hub;