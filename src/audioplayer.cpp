#include <QMessageBox>

#include "audioplayer.h"
#include "audioplayerprivate.h"

AudioPlayer  * pAudioPlayer;

//
// Audio player wrapper class
//

AudioPlayer::AudioPlayer()
{
	d = new AudioPlayerPrivate();
}

AudioPlayer::~AudioPlayer()
{
	delete d;
}

bool AudioPlayer::init()
{
	return d->init();
}

bool AudioPlayer::open( const QString& filename )
{
	return d->open( filename );
}

void AudioPlayer::play()
{
	d->play();
}

void AudioPlayer::reset()
{
	d->reset();
}

void AudioPlayer::stop()
{
	d->stop();
}

void AudioPlayer::seekTo( qint64 value )
{
	d->seekTo( value );
}

bool AudioPlayer::isPlaying() const
{
	return d->isPlaying();
}

qint64 AudioPlayer::currentTime() const
{
	return d->currentTime();
}

qint64 AudioPlayer::totalTime() const
{
	return d->totalTime();
}

QString	AudioPlayer::errorMsg() const
{
	return d->errorMsg();
}

void AudioPlayer::emitTickSignal( qint64 tickvalue )
{
	emit tick( tickvalue );
}