#pragma once

/*!
 * @brief Accessor
 * @param[in] Tag private�����o�ɃA�N�Z�X����Tag�N���X
 */
template <class Tag>
struct Accessor {
  typedef typename Tag::type type;  //!< �����o�̌^
  static type ptr_;  //!< �����o�|�C���^
};

/*
 * @brief static�����o�̎���
 * @param[in] Tag private�����o�ɃA�N�Z�X����Tag�N���X
 * @details
 * �A�N�Z�X�������^�̃����o�|�C���^��ێ�����.
 */
template <class Tag>
typename Accessor<Tag>::type Accessor<Tag>::ptr_;

/*
 * @brief Initializer
 * @param[in] Tag private�����o�ɃA�N�Z�X����Tag�N���X
 * @param[in] ptr �A�N�Z�X�������^�̃����o�|�C���^
 * @details
 * �A�N�Z�X�������^�̃����o�|�C���^��ێ�����.
 */
template <class Tag, typename Tag::type ptr>
struct Initializer : Accessor<Tag> {
  /*!
   * @brief �R���X�g���N�^
   * @details
   * Accessor�^��static�����o value �Ƀ����o�|�C���^ ptr ��ݒ肷��.
   */
  Initializer() {
    Accessor<Tag>::ptr_ = ptr;
  }

  static Initializer instance_;  //!< �C���X�^���X
};

/*!
 * @brief 
 * @details
 * �������g�� static �I�u�W�F�N�g�̒�` explicit instantiation �ɂ����
 * main() �̑O�ɐ�������邱�ƂɂȂ�.
 * �����̍ۂɏ����������s���邽�߂̃R���X�g���N�^���Ăяo�����.
 */
template <typename Tag, typename Tag::type ptr>
typename Initializer<Tag, ptr> Initializer<Tag, ptr>::instance_;
