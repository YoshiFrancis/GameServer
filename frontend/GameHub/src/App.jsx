import { useState, useEffect } from 'react'
import Hub from './components/Hub'
import Lobby from './components/Lobby'
import UnoGame from './components/UnoGame'
import { socket } from './socket'
import './App.css'

function App() {
  const [isConnected, setIsConnected] = useState(socket.connected);

  useEffect(() => {
    function onConnect() {
      console.log("hello")
      setIsConnected(true);
    }

    function onDisconnect() {
      setIsConnected(false);
    }

    function onFooEvent(value) {
      setFooEvents(previous => [...previous, value]);
    }


    socket.on('connect', onConnect);
    socket.on('disconnect', onDisconnect);
    socket.on('foo', onFooEvent);

    socket.connect()

    return () => {
      socket.off('connect', onConnect);
      socket.off('disconnect', onDisconnect);
      socket.off('foo', onFooEvent);
    };
  }, []);

  return (
    <>
      <Hub />
      <Lobby />
      <UnoGame />
    </>
  )
}

export default App
